/*
 * frontdevice.cpp
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
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "widget.h"
#include "frontdevice.h"
#include "fpbttn.h"
#include "debug.h"
frontdevice::frontdevice(device *p,device *n):device(p,n){
debug("frontdevice::frontdevice")
*(QString*)idstr=FRONT;
vlt->addWidget(tlbl=new QLabel("<p><span style=\"font-family:Tw Cen MT;font-size:14pt;color:#00409e\"<b>Setup - "NAME_STR"</b></span><br><br>Welcome to "NAME_STR" Setup Wizard</p>"),0,Qt::AlignTop);
QHBoxLayout *hlt=new QHBoxLayout;
hlt->addStretch(1);
hlt->addWidget(npb=new fpbttn(tr("&Next")),0,Qt::AlignRight);
hlt->addWidget(epb=new fpbttn("&Exit"),0,Qt::AlignRight);
vlt->addLayout(hlt);
connect(epb,SIGNAL(clicked()),wdgt,SLOT(close()));
connect(npb,SIGNAL(clicked()),this,SLOT(slotnpbclicked()));
}
void frontdevice::unhide(){
debug("frontdevice::unhide")
tlbl->setVisible(true);
npb->setVisible(true);
epb->setVisible(true);
debug("~frontdevice::unhide")
}
void frontdevice::hide(){
debug("frontdevice::hide")
tlbl->hide();
npb->hide();
epb->hide();
debug("~frontdevice::hide")
}
