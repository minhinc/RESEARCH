/*
 * nmainwindow.cpp
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
/* implements nmainwindow methods */
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGLWidget>
#include <QWebFrame>
#include <QWebElement>
#include "nmainwindow.h"
#include "ngraphicswebview.h"
#include "airplane.h"
#include "ndebug.h"
nmainwindow::nmainwindow(QWidget *p):QMainWindow(p) {
trace("nmainwindow::nmainwindow")
 setWindowTitle("3D graphics on google_map");
 setWindowIcon(QIcon("qrc:/topicon.png"));
 dv=new airplane(this);
 gs=new QGraphicsScene(0,0,1024,768);
 gview = new QGraphicsView(gs,this);
 gview->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
 gview->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
 gview->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
 glwidget=new QGLWidget(QGLFormat(QGL::SampleBuffers));
 glwidget->makeCurrent();
 QWebSettings::globalSettings()->setAttribute(QWebSettings::AcceleratedCompositingEnabled, true);
 gwv=new ngraphicswebview(this);
 gview->setScene(gs);
 gs->addItem(gwv);
 gwv->setResizesToContents(true);
 gview->setViewport(glwidget);
 setCentralWidget(gview);
 connect(gwv,SIGNAL(loadFinished(bool)),dynamic_cast<airplane*>(dv),SLOT(init()));
 init();
showMaximized();
displaylogo=false;
 trace("~nmainwindow::nmainwindow")
}
void nmainwindow::init() {
 trace("/nmainwindow::init")
 gwv->setUrl(QUrl("qrc:/google_maps.html"));
}
void nmainwindow::update(ngraphicswebview*) {
 trace("/nmainwindow::update(ngraphicswebview")
 dv->draw(glwidget->width(),glwidget->height());
}
void nmainwindow::update(device*, const QString& strpar) {
 trace("/nmainwindow::update(device)")
 gwv->page()->currentFrame()->documentElement().evaluateJavaScript(strpar);
}
