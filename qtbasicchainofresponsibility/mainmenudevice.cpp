/*
 * mainmenudevice.cpp
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
#include <QStandardPaths>
#include <QDir>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDir>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include "widget.h"
#include "mainmenudevice.h"
#include "fpbttn.h"
#include "debug.h"
#include "fpbttn.h"
mainmenudevice::mainmenudevice(device *p,device *n):device(p,n){
debug("mainmenudevice::mainmenudevice")
*(QString*)idstr=MENU;
vlt->addWidget(tlbl=new QLabel("<span style=\"font-size:14pt;font-family:'Tw Cen Mt';color:#00409e\">Start Menu shortcuts</span><br><br>Select the Start Menu in which you would like to create the<br>progrem's shortcuts. You can also enter a name to create a<br>new folder."),0,Qt::AlignTop);
vlt->addWidget(led=new QLineEdit("gfd"));
vlt->addWidget(lwgt=new QListWidget);
QDir dir(QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation));
lwgt->addItems(dir.entryList(QDir::Dirs|QDir::NoDotAndDotDot));
vlt->addStretch(1);
QHBoxLayout *hlt=new QHBoxLayout;
hlt->addWidget(ppb=new ppbttn,1,Qt::AlignLeft);
hlt->addWidget(npb=new fpbttn("&Next"),0,Qt::AlignRight);
hlt->addWidget(epb=new fpbttn("&Exit"));
vlt->addLayout(hlt);
connect(npb,SIGNAL(clicked()),this,SLOT(slotnpbclicked()));
connect(ppb,SIGNAL(clicked()),this,SLOT(slotppbclicked()));
connect(epb,SIGNAL(clicked()),wdgt,SLOT(close()));
debug("~mainmenudevice::mainmenudevice")
}
void mainmenudevice::unhide(){
debug("mainmenudevice::unhide")
tlbl->setVisible(true);
led->setVisible(true);
lwgt->setVisible(true);
ppb->setVisible(true);
npb->setVisible(true);
epb->setVisible(true);
debug("~mainmenudevice::unhide")
}
void mainmenudevice::hide(){
debug("mainmenudevice::hide")
tlbl->setVisible(false);
led->setVisible(false);
lwgt->setVisible(false);
ppb->setVisible(false);
npb->setVisible(false);
epb->setVisible(false);
debug("/mainmenudevice::hide")
}
void mainmenudevice::slotnpbclicked() {
debug("mainmenudevice::slotnpbclicked")
*(QString*)wdgt->mmn=led->text();
device::slotnpbclicked();
debug("~mainmenudevice::slotnpbclicked")
}
