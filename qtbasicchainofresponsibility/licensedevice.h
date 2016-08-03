/*
 * licensedevice.h
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
#ifndef LICENSEDEVICE_H
#define LICENSEDEVICE_H
#include "device.h"
struct QTextEdit;
struct QCheckBox;
struct licensedevice:device{
licensedevice(device *prev=NULL,device *next=NULL);
QTextEdit *ted;
QCheckBox *acb;
void hide();
void* identity();
void unhide();
private slots:
void slotacbstatechanged(int);
private:
Q_OBJECT
};
#endif
