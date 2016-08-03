/*
 * licensedevice.cpp
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
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QCheckBox>
#include "widget.h"
#include "licensedevice.h"
#include "fpbttn.h"
#include "debug.h"
licensedevice::licensedevice(device *p,device *n):device(p,n){
debug("licensedevice::licensedevice")
*(QString*)idstr=LIC;
vlt->addWidget(tlbl=new QLabel("<span style=\"font-size:14pt;font-family:'Tw Cen Mt';color:#00409e\">License Agreement</span><br><br>You must accept "NAME_STR" Terms in order to continue."),0,Qt::AlignTop);
vlt->addWidget(ted=new QTextEdit);
QFile file(":/lic.txt");
file.open(QIODevice::ReadOnly);
ted->setText(file.readAll());
vlt->addWidget(acb=new QCheckBox("Click here to accept terms and conditions."));
acb->setCheckState(Qt::Unchecked);
vlt->addStretch(1);
QHBoxLayout *hlt=new QHBoxLayout;
hlt->addWidget(ppb=new ppbttn,1,Qt::AlignLeft);
hlt->addWidget(npb=new fpbttn("&Next"),0,Qt::AlignRight);
npb->setDisabled(true);
hlt->addWidget(epb=new fpbttn("&Exit"));
vlt->addLayout(hlt);
connect(npb,SIGNAL(clicked()),this,SLOT(slotnpbclicked()));
connect(ppb,SIGNAL(clicked()),this,SLOT(slotppbclicked()));
connect(epb,SIGNAL(clicked()),wdgt,SLOT(close()));
connect(acb,SIGNAL(stateChanged(int)),this,SLOT(slotacbstatechanged(int)));
debug("~mainmenudevice::mainmenudevice")
}
void licensedevice::unhide(){
debug("licensedevice::unhide")
tlbl->setVisible(true);
ted->setVisible(true);
ppb->setVisible(true);
npb->setVisible(true);
epb->setVisible(true);
acb->setVisible(true);
debug("~licensedevice::unhide")
}
void licensedevice::hide(){
debug("licensedevice::hide")
tlbl->setVisible(false);
ted->setVisible(false);
ppb->setVisible(false);
npb->setVisible(false);
epb->setVisible(false);
acb->setVisible(false);
debug("~licensedevice::hide")
}
void licensedevice::slotacbstatechanged(int state){
debug("licensedevice::slotacbstatechanged")
npb->setDisabled(!state);
debug("licensedevice::slotacbstatechanged")
}
