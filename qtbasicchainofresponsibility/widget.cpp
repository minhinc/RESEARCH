/*
 * widget.cpp
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
#include <QFile>
#include <QRegularExpression>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QIcon>
#include "widget.h"
#include "frontdevice.h"
#include "licensedevice.h"
#include "dirdevice.h"
#include "treedevice.h"
#include "mainmenudevice.h"
#include "lastdevice.h"
#include "debug.h"
widget::widget(QWidget *p):QWidget(p){
device::wdgt=this;
device *tdv;
resize(486,354);
setWindowFlags(Qt::MSWindowsFixedSizeDialogHint|Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
idir=new QString("Not specified");
mmn=new QString("Not specified");
source=0;
QFile file(":/request.txt");
file.open(QIODevice::ReadOnly);
rlst=new QStringList;
*(QStringList*)rlst=QString(file.readAll()).split(QRegularExpression("\\s+"),QString::SkipEmptyParts);
file.close();
tdv=dv=new frontdevice(NULL,new licensedevice(NULL,new dirdevice(NULL,new treedevice(NULL, new mainmenudevice(NULL, new lastdevice(NULL,NULL))))));
while(tdv->next!=NULL){
tdv->next->prev=tdv;
tdv=tdv->next;
}
QHBoxLayout *hlt=new QHBoxLayout;
QLabel *lbl=new QLabel;
QPixmap pixmap(":/install.png");
lbl->setPixmap(pixmap);
hlt->addWidget(lbl);
hlt->addLayout(vlt=dv->vlt,1);
setLayout(hlt);
dv->work();
setWindowIcon(QIcon(":/topicon.png"));
setWindowTitle(NAME_STR" Setup");
}
widget::~widget(){
debug("widget::~widget")
delete (QString*)idir;
delete (QString*)mmn;
delete dv;
delete (QStringList*)rlst;
debug("~widget::~widget")
}
