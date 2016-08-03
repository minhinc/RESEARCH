/*
 * lastdevice.cpp
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
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <widget.h>
#include "fpbttn.h"
#include "lastdevice.h"
#include "fpbttn.h"
#include "debug.h"
lastdevice::lastdevice(device *p,device *n):device(n,p){
debug("lastdevice::lastdevice")
*(QString*)idstr=LAST;
vlt->addWidget(tlbl=new QLabel("<span style=\"font-family:'Tw Cen Mt';font-size:14pt;color:#00409e\">Ready to Install</span><br><br>Setup is now ready to begin installing "NAME_STR" on your computer."),0,Qt::AlignTop);
vlt->addWidget(dpb=new QPushButton("Show Details"),0,Qt::AlignLeft);
vlt->addWidget(dte=new QTextEdit);
dte->setVisible(false);
dte->setReadOnly(true);
vlt->addStretch(1);
QHBoxLayout *hlt=new QHBoxLayout;
hlt->addWidget(ppb=new ppbttn,1,Qt::AlignLeft);
hlt->addWidget(ipb=new fpbttn("Install"),0,Qt::AlignRight);
hlt->addWidget(epb=new fpbttn("&Exit"));
vlt->addLayout(hlt);
connect(ppb,SIGNAL(clicked()),this,SLOT(slotppbclicked()));
connect(ipb,SIGNAL(clicked()),this,SLOT(slotipbclicked()));
connect(epb,SIGNAL(clicked()),wdgt,SLOT(close()));
connect(dpb, SIGNAL(clicked()),this,SLOT(slotdpbclicked()));
debug("~lastdevice::lastdevice")
}
void lastdevice::slotipbclicked(){
debug("lastdevice::slotipbclicked")
}
void lastdevice::unhide(){
debug("lastdevice::unhide")
tlbl->setVisible(true);
ppb->setVisible(true);
epb->setVisible(true);
ipb->setVisible(true);
dpb->setVisible(true);
if(dpb->text()=="Hide Details")
dte->setVisible(true);
debug("~lastdevice::unhide")
}
void lastdevice::hide(){
debug("lastdevice::hide")
tlbl->setVisible(false);
ppb->setVisible(false);
epb->setVisible(false);
ipb->setVisible(false);
dpb->setVisible(false);
dte->setVisible(false);
debug("~lastdevice::hide")
}
void lastdevice::slotdpbclicked(){
debug("lastdevice::slotdpbclicked")
dte->setHtml(QString("%1 : %2<br><br>%3 ? %4<br><br>%5 : %6").arg("<b>INSTALLATION DIRECTORY</b>").arg(*(QString*)wdgt->idir+"\\gfd").arg("<b>INSTALL SOURCE</b>").arg(wdgt->source?"Yes":"No").arg("<b>MAIN MENU ENTRY</b>").arg(*(QString*)wdgt->mmn));
if(dpb->text()=="Show Details"){
dte->setVisible(true);
dpb->setText("Hide Details");
}else{
dte->setVisible(false);
dpb->setText("Show Details");
}
debug("~lastdevice::slotdpbclicked")
}
