/*
 * ngraphicswebview.h
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
#ifndef NGRAPHICSWEBVIEW_H
#define NGRAPHICSWEBVIEW_H
#include <QGraphicsWebView>
class QNetworkDiskCache;
class nmainwindow;
class ngraphicswebview:public QGraphicsWebView {
Q_OBJECT
public:
 ngraphicswebview(nmainwindow *p=0);
protected:
 virtual void paint(QPainter *p, const QStyleOptionGraphicsItem *options, QWidget *widget);
private:
 QNetworkDiskCache *dc;
 nmainwindow *mediator;
};
#endif//NGRAPHICSWEBVIEW_H
