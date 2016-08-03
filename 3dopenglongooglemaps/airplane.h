/*
 * airplane.h
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
#ifndef AIRPLANE_H
#define AIRPLANE_H
class QTimer;
class QMenu;
class QAction;
class QContextMenuEvent;
class QSlider;
class nmainwindow;
class QNetworkAccessManager;
class QNetworkReply;
#include <QObject>
#include <QList>
#include <QStringList>
#include <QString>
#include "device.h"
class airplane:public QObject, public device{
Q_OBJECT
public:
 airplane(nmainwindow *mp=0);
 ~airplane();
 void readfile(const QString& gpfile);
 void draw(int w, int h);
public slots:
 void init();
private slots:
 void refreshmap();
 void replyFinished(QNetworkReply*);
 void roadmaptriggered();
 void satellitetriggered();
 void hybridtriggered();
 void terraintriggered();
 void pausetriggered();
 void snapshottriggered();
 void abouttriggered();
 void slider();
 void slidervaluechanged(int);
private:
 QMenu *cmenu;
 QMenu *ctrlmenu;
 QAction *roadmapaction;
 QAction *satelliteaction;
 QAction *terrainaction;
 QAction *hybridaction;
 QAction *pauseaction;
 QAction *slideraction;
 QAction *snapshotaction;
 QAction *aboutaction;
 QTimer *timer;
 QNetworkAccessManager *pnam;
 QNetworkReply *nr;
 QWidget *w;
 QSlider *sldr;
 QStringList clmnlst;
 QList<QStringList> linelst;
 nmainwindow *mediator;
 int lineindex;
 int xRot;
 int yRot;
 int zRot;
 int pzRot;
 int plineindex;
private:
 void setmarker();
};
#endif
