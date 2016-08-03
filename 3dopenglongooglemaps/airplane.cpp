/*
 * airplane.cpp
 * Qt 3D OpenGL on Google Maps
 * Copyright (c) 2015-2016 Minh Inc www.minhinc.com
 *
 * This file is part of Qt3DOpenGLOnGoogleMaps
 *
 * Qt3DOpenGLOnGoogleMaps is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * Qt3DOpenGLOnGoogleMaps is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with Mgmp; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
/* implements airplane class methods, adds menus to mainwindow */
#include <QGLWidget>
#include <QTimer>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFile>
#include <QTextStream>
#include <QContextMenuEvent>
#include <QStatusBar>
#include <QSlider>
#include <qmath.h>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QMessageBox>
#include "ndebug.h"
#include "airplane.h"
#include "utility.h"
#include "nmainwindow.h"

/*airplane constructor reads conf file and intializes menu controls in mediator(mainwindow)*/
airplane::airplane(nmainwindow *m):w(NULL),mediator(m) {
trace("airplane::airplane")
 timer=new QTimer(this);
 connect(timer,SIGNAL(timeout()),this,SLOT(refreshmap()));
 readfile(":/conf.txt");
 cmenu=mediator->menuBar()->addMenu(tr("map"));
 roadmapaction=new QAction(tr("ROADMAP"),cmenu);
 satelliteaction=new QAction(tr("SATELLITE"),cmenu);
 hybridaction=new QAction(tr("HYBRID"),cmenu);
 terrainaction=new QAction(tr("TERRAIN"),cmenu);
 ctrlmenu=mediator->menuBar()->addMenu(tr("ctrl"));
 pauseaction=new QAction(tr("pause"),ctrlmenu);
 slideraction=new QAction(tr("slider"),ctrlmenu);
 snapshotaction=new QAction(tr("snapshot"),ctrlmenu);
aboutaction=new QAction(tr("about"),mediator->menuBar());
 connect(roadmapaction,SIGNAL(triggered()),this,SLOT(roadmaptriggered()));
 connect(satelliteaction,SIGNAL(triggered()),this,SLOT(satellitetriggered()));
 connect(terrainaction,SIGNAL(triggered()),this,SLOT(terraintriggered()));
 connect(hybridaction,SIGNAL(triggered()),this,SLOT(hybridtriggered()));
 connect(pauseaction,SIGNAL(triggered()),this,SLOT(pausetriggered()));
 connect(slideraction,SIGNAL(triggered()),this,SLOT(slider()));
 connect(snapshotaction,SIGNAL(triggered()),this,SLOT(snapshottriggered()));
connect(aboutaction,SIGNAL(triggered()),this,SLOT(abouttriggered()));
 cmenu->addAction(roadmapaction);
 cmenu->addAction(satelliteaction);
 cmenu->addAction(hybridaction);
 cmenu->addAction(terrainaction);
 ctrlmenu->addAction(pauseaction);
 ctrlmenu->addAction(slideraction);
 ctrlmenu->addSeparator();
 ctrlmenu->addAction(snapshotaction);
mediator->menuBar()->addAction(aboutaction);
 pzRot=plineindex=lineindex=0;
trace("~airplane::airplane")
}

/*read the conf file*/
void airplane::readfile(const QString& conffile) {
trace("airplane::readfile "<<conffile)
 QString line;
 QFile ifile(conffile);
// QFile ifile(":/conf.txt");
 if(!ifile.open(QFile::ReadOnly)) {
trace(conffile<<"not found")
 exit(-1);
 }
while(!ifile.atEnd()){
line=ifile.readLine();
if(line.isEmpty() || line.contains(QRegExp("^\\s+$")))
continue;
 clmnlst=line.split(QRegExp("\\s+"),QString::SkipEmptyParts);
 trace("airplane::readfile lat, lang, alt"<<clmnlst.at(0)<<" "<<clmnlst.at(1)<<" "<<clmnlst.at(2));
 linelst.push_back(clmnlst);
 }
 ifile.close();
 trace("~airplane::readfile, read line count "<<linelst.size());
}

/*called from ngraphicswebview(QGraphicsWebView)::paint in order to have 3D drawing*/
void airplane::draw(int w, int h) {
trace("airplane::draw, w, h"<<w<<" "<<h)
 GLfloat altdelta=0,langdelta=0,latdelta=0;
 uc utlt;
 glShadeModel(GL_SMOOTH);
 glViewport(0,0,w,h);
 glEnable(GL_DEPTH_TEST);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 if(w>h)
 glOrtho(-ORTHOWHBT*(GLfloat)w/(GLfloat)h,ORTHOWHBT*(GLfloat)w/(GLfloat)h,-ORTHOWHBT,ORTHOWHBT,0.0,100.0);
 else
 glOrtho(-ORTHOWHBT,ORTHOWHBT,-ORTHOWHBT*(GLfloat)h/(GLfloat)w,ORTHOWHBT*(GLfloat)h/(GLfloat)w,0.0,100.0);
 glMatrixMode(GL_MODELVIEW);
 glClear(GL_DEPTH_BUFFER_BIT);
 glLoadIdentity();
 glTranslatef(0.0,0.0,-50.0);
 if(lineindex+1 < linelst.size()) {
 altdelta=linelst.at(lineindex+1).at(2).toFloat()-linelst.at(lineindex).at(2).toFloat();
 langdelta=linelst.at(lineindex+1).at(1).toFloat()-linelst.at(lineindex).at(1).toFloat();
 latdelta=linelst.at(lineindex+1).at(0).toFloat()-linelst.at(lineindex).at(0).toFloat();
 langdelta=langdelta*100*100;
 latdelta=latdelta*100*100;
 if(plineindex != lineindex) {
 plineindex=lineindex;
 pzRot=zRot;
 }
 xRot=(180/PI)*(GLfloat)qAtan2(altdelta,qSqrt(qPow(langdelta,2)+qPow(latdelta,2)));
 zRot=-(180/PI)*(GLfloat)qAtan2(langdelta,latdelta);
// yRot=(GLfloat)(((pzRot-zRot)*(xRot/(qAbs(xRot)+0.0001)))/4);
if((pzRot-zRot)<-180)
yRot=(GLfloat)(360+pzRot-zRot)*0.1;
else
yRot=(GLfloat)(pzRot-zRot)*0.1;
 trace("airplane::draw altdelta, latdelta, langdelta, xRot, yRot, zRot, pzRot, lineindex "<<altdelta<<" "<<latdelta<<" "<<langdelta<<" "<<xRot<<" "<<yRot<<" "<<zRot<<" "<<pzRot<<" "<<lineindex<<" "<<linelst.at(lineindex).at(0)<<linelst.at(lineindex).at(1)<<linelst.at(lineindex).at(2))
 }
 glRotatef(zRot,0.0,0.0,1.0);
 glRotatef(xRot,1.0,0.0,0.0);
 glRotatef(yRot,0.0,1.0,0.0);
 utlt.drawcone(3,42.0,37.5,uc(0.8,0.8,0.0),uc(1.0,0.0,0.0),-PI/4,5*PI/4);
 utlt.drawcylinder(4,6,37.5,25.0,uc(1.0,0.0,0.0),uc(0.6,0.0,0.0),-PI/4,5*PI/4);
 utlt.drawcylinder(6.5,6.5,25.0,2.0,uc(1.0,0.0,0.0),uc(0.6,0.0,0.0),-PI/4,5*PI/4);
 utlt.drawcylinder(6.5,1.0,2.0,-35.0,uc(1.0,0.0,0.0),uc(0.6,0.0,0.0),-PI/4,5*PI/4);
 utlt.drawcuboid(uc(48.0,9.0,-0.125),uc(48.0,16.0,-0.125),uc(48.0,9.0,0.125),uc(48.0,16.0,0.125),uc(6.5,6.5,0.25),uc(6.5,17.0,0.25),
 uc(6.5,6.5,-0.25),uc(6.5,17.0,-0.25),uc(0.0,0.25,0.0));
 utlt.drawcuboid(uc(48.0,7.0,0.0),uc(48.0,9.0,0.0),uc(48.0,7.0,0.05),uc(48.0,9.0,0.125),uc(6.5,2.0,0.0),uc(6.5,6.5,0.0),uc(6.5,2.0,0.05),
 uc(6.5,6.5,0.25),uc(0.25,0.5,0.5));
 utlt.drawcuboid(uc(-48.0,9.0,-0.125),uc(-48.0,16.0,-0.125),uc(-48.0,9.0,0.125),uc(-48.0,16.0,0.125),uc(-6.5,6.5,0.25),uc(-6.5,17.0,0.25),
 uc(-6.5,6.5,-0.25),uc(-6.5,17.0,-0.25),uc(0.0,0.25,0.0));
 utlt.drawcuboid(uc(-48.0,7.0,0.0),uc(-48.0,9.0,0.0),uc(-48.0,7.0,0.05),uc(-48.0,9.0,0.125),uc(-6.5,2.0,0.0),uc(-6.5,6.5,0.0),uc(-6.5,2.0,0.05),
 uc(-6.5,6.5,0.25),uc(0.25,0.5,0.5));
 utlt.drawcuboid(uc(-1.0,-35.0,0.0),uc(-2.0,-26.0,0.0),uc(-1.0,-35.0,0.125),uc(-2.0,-26.0,0.125),
 uc(-15.0,-35.0,0.125),uc(-15.0,-29.0,0.125),uc(-15.0,-35.0,0.0),uc(-15.0,-35.0,0.0),uc(0.0,0.6,0.0));
 utlt.drawcuboid(uc(-1.0,-39.0,0.0),uc(-1.0,-35.0,0.0),uc(-1.0,-39.0,0.125),uc(-1.0,-35.0,0.125),
 uc(-15.0,-38.0,0.125),uc(-15.0,-35.0,0.125),uc(-15.0,-38.0,0.0),uc(-15.0,-35.0,0.0),uc(0.0,0.25,0.0));
 utlt.drawcuboid(uc(1.0,-35.0,0.0),uc(2.0,-26.0,0.0),uc(1.0,-35.0,0.125),uc(2.0,-26.0,0.125),
 uc(15.0,-35.0,0.125),uc(15.0,-29.0,0.125),uc(15.0,-35.0,0.0),uc(15.0,-35.0,0.0),uc(0.0,0.6,0.0));
 utlt.drawcuboid(uc(1.0,-39.0,0.0),uc(1.0,-35.0,0.0),uc(1.0,-39.0,0.125),uc(1.0,-35.0,0.125),
 uc(15.0,-38.0,0.125),uc(15.0,-35.0,0.125),uc(15.0,-38.0,0.0),uc(15.0,-35.0,0.0),uc(0.0,0.25,0.0));
 utlt.drawcuboid(uc(-1.0,-42.0,0.0),uc(1.0,-42.0,0.0),uc(-0.5,-40.0,8.0),uc(0.5,-40.0,8.0),uc(-0.5,-35.0,8.0),uc(0.5,-35.0,8.0),
 uc(-1.0,-30.0,0.0),uc(1.0,-30.0,0.0),uc(0.4,0.2,0.0));
 utlt.drawcuboid(uc(-0.5,-40.0,8.0),uc(0.5,-40.0,8.0),uc(-0.5,-40.0,10.0),uc(0.5,-40.0,10.0),uc(-0.5,-36.0,10.0),uc(0.5,-36.0,10.0),
 uc(-0.5,-35.0,8.0),uc(0.5,-35.0,8.0),uc(0.6,0.3,0.0));
 glPushMatrix();
 glTranslatef(-15.0,0.0,-2.4);
 utlt.drawcylinder(2.0,2.0,17.0,6.5,uc(0.0,0.0,1.0),uc(0.0,0.0,1.0));
 glPopMatrix();
 glPushMatrix();
 glTranslatef(-25.0,0.0,-2.4);
 utlt.drawcylinder(2.0,2.0,17.0,6.5,uc(0.0,0.0,1.0),uc(0.0,0.0,1.0));
 glPopMatrix();
 glPushMatrix();
 glTranslatef(15.0,0.0,-2.4);
 utlt.drawcylinder(2.0,2.0,17.0,6.5,uc(0.0,0.0,1.0),uc(0.0,0.0,1.0));
 glPopMatrix();
 glPushMatrix();
 glTranslatef(25.0,0.0,-2.4);
 utlt.drawcylinder(2.0,2.0,17.0,6.5,uc(0.0,0.0,1.0),uc(0.0,0.0,1.0));
 glPopMatrix();
 trace("~airplane::draw");
}

/*Every some timeinterval refresh/move the map, required for animation effect*/
void airplane::refreshmap() {
trace("airplane::refreshmap")
 int lzoom;
 if((lineindex+1) == linelst.size()) {
 timer->stop();
 return;
 }
 else ++lineindex;
// lzoom=16-linelst.at(lineindex).at(2).toDouble()*0.001;
 lzoom=19.4-linelst.at(lineindex).at(2).toDouble()*0.0013;
 QString statusbarmsg=QString("LAT %1, LANG %2, ALT %3, ZOOM %4").arg(linelst.at(lineindex).at(0)).arg(linelst.at(lineindex).at(1)).arg(linelst.at(lineindex).at(2)).arg(lzoom);
 QString str=
 QString("var  newLoc = new google.maps.LatLng(%1,%2); ").arg(linelst.at(lineindex).at(0)).arg(linelst.at(lineindex).at(1)) +
 QString("map.setCenter(newLoc);") +
 QString("map.setZoom(%1);").arg(lzoom);
 mediator->update(this,str);
draw(400,300);
 mediator->statusBar()->showMessage(statusbarmsg);
 if(w!=NULL)
 sldr->setValue(lineindex);
 trace("~airplane::refreshmap"<<lineindex);
}

/*initialize the timer and setmarker*/
void airplane::init() {
trace("airplane::init")
 if(pauseaction->text() == "continue") {
 trace("restart fired when ctrl is paused, changing it back to continue mode")
 pauseaction->setText("pause");
 }
 setmarker();
 if(linelst.size()>1)
 timer->start(TIMEOUT);
trace("~airplane::init")
}

/*placeholder at source and destination*/
void airplane::setmarker() {
trace("airplane::setmarker")
 QString url=QString("http://maps.google.com/maps/api/geocode/json?latlng=%1,%2&sensor=false&language=en").arg(linelst.at(0).at(0)).arg(linelst.at(0).at(1));
 pnam=new QNetworkAccessManager(this);
 connect(pnam,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));
 nr=pnam->get(QNetworkRequest(QUrl(url)));
 url=QString("http://maps.google.com/maps/api/geocode/json?latlng=%1,%2&sensor=false&language=en").arg(linelst.at(linelst.size()-1).at(0)).arg(linelst.at(linelst.size()-1).at(1));
 pnam->get(QNetworkRequest(QUrl(url)));
 trace("~airplane::setmarker")
}

void airplane::replyFinished(QNetworkReply* reply){
trace("airplane::replyFinished")
 QString json;
 QJsonDocument jd;
 QString placename;
 QString positionstr;
 QString srcmarker;
 if(reply->error()) {
 trace("Network Error while fetching json data, only showing marker not the tag")
 placename="";
 } else {
 json=reply->readAll();
 jd=QJsonDocument::fromJson(json.toLatin1());
 placename=jd.object().value("results").toArray().takeAt(0).toObject().value("formatted_address").toString();
 }
 if(reply==nr)
 positionstr=QString("position: new google.maps.LatLng(%1, %2),").arg(linelst.at(0).at(0)).arg(linelst.at(0).at(1));
 else
 positionstr=QString("position: new google.maps.LatLng(%1, %2),").arg(linelst.at(linelst.size()-1).at(0)).arg(linelst.at(linelst.size()-1).at(1));
 srcmarker=
 QString("var marker = new google.maps.Marker({") +
 positionstr +
 QString("map: map,") +
 QString("title: %1").arg("\""+placename+"\"") +
 QString("});") +
 QString("markers.push(marker);");
 mediator->update(this,srcmarker);
 trace("~airplane::replyfinished")
}

void airplane::roadmaptriggered() {
 mediator->update(this,"map.setMapTypeId(google.maps.MapTypeId.ROADMAP)");
}
void airplane::satellitetriggered() {
 mediator->update(this,"map.setMapTypeId(google.maps.MapTypeId.SATELLITE)");
}
void airplane::hybridtriggered() {
 mediator->update(this,"map.setMapTypeId(google.maps.MapTypeId.HYBRID)");
}
void airplane::terraintriggered() {
 mediator->update(this,"map.setMapTypeId(google.maps.MapTypeId.TERRAIN)");
}

void airplane::pausetriggered() {
 if(pauseaction->text() == "pause") {
 timer->stop();
 pauseaction->setText(tr("continue"));
 }else {
 timer->start(TIMEOUT);
 pauseaction->setText(tr("pause"));
 }
}

void airplane::snapshottriggered() {
 trace("/airplane::snapshottriggered")
 mediator->glwidget->grabFrameBuffer().save("C:/framebuffer.png","PNG",100);
}

void airplane::slider() {
trace("airplane::slider")
 if(w==NULL) {
 trace("widget found null, creating")
 w=new QWidget;
 sldr=new QSlider(Qt::Horizontal,w);
 sldr->setGeometry(40,20,120,20);
 sldr->setRange(0,linelst.size()-1);
 sldr->setValue(lineindex);
 connect(sldr,SIGNAL(valueChanged(int)),this,SLOT(slidervaluechanged(int)));
 w->setFixedSize(200,60);
 }
 w->raise();
 w->show();
 trace("~airplane::slider")
}

void airplane::slidervaluechanged(int val) {
trace("airplane::slidervaluechanged "<<val)
 if(val !=lineindex) {
 trace("airplane::slidervaluechanged, val not found equal to lineindex"<<val<<" "<<lineindex)
 lineindex=val;
 if(!timer->isActive())
 timer->start(TIMEOUT);
 }
 trace("~airplane::slidervaluechanged")
}

airplane::~airplane() {
trace("/airplane::~airplane")
 delete w;
}
void airplane::abouttriggered(){
trace("/airplane::abouttriggered")
QMessageBox::about(mediator,tr("Minh Inc."),tr("OpenGL 3D graphics on google map.\nDesigned and Developed at Minh Inc., \nwww.minhinc.com\nBased on Qt5 QtWebKit APIs"));
mediator->displaylogo=!mediator->displaylogo;
}
