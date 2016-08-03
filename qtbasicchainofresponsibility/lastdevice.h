/*
 * lastdevice.h
 * Qt Basic: Chain of Responsibility
 * Copyright (c) 2015-2016 Minh Inc www.minhinc.com
 *
 * This file is part of QtBasicChainOfResponsibility
 *
 * QtBasicChainOfResponsibility is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * QtBasicChainOfResponsibility is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with Mgmp; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
#ifndef LASTDEVICE_H
#define LASTDEVICE_H
#include "device.h"
struct QLabel;
struct QTextEdit;
struct QPushButton;
struct fpbttn;
struct lastdevice:device{
lastdevice(device *p=NULL,device *n=NULL);
void unhide();
void* identity();
void hide();
QPushButton *dpb;
QTextEdit *dte;
fpbttn *ipb;
private slots:
void slotipbclicked();
void slotdpbclicked();
private:
Q_OBJECT
};
#endif
