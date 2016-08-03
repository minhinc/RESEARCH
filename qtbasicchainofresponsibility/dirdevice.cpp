/*
 * dirdevice.cpp
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
#include <QFileDialog>
#include <QFile>
#include <QStandardPaths>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include "widget.h"
#include "dirdevice.h"
#include "fpbttn.h"
#include "debug.h"
dirdevice::dirdevice(device* p,device *n):device(p,n){
debug("dirdevice::dirdevice")
*(QString*)(wdgt->idir)=qgetenv("PROGRAMFILES");
QGridLayout *glt=new QGridLayout;
*(QString*)idstr=DIR;
vlt->addWidget(tlbl=new QLabel("<p><span style=\"font-size:14pt;font-family:'Tw Cen Mt';color:#00409e\">Installation Folder</span></p>"),0,Qt::AlignTop);
glt->addWidget(lbl=new QLabel("<p style=\"color:#222222\">Choose installation directory</p>"),0,0,1,1);
glt->addWidget(led=new QLineEdit,1,0,1,1);
led->setText(*(QString*)wdgt->idir+"\\gfd");
glt->addWidget(dpb=new fpbttn("..."),1,1,1,1,Qt::AlignTop);
glt->addWidget(elbl=new QLabel("<p style=\"color:#ff0000\">gfd directory exists, it will be overwritten</p>"),2,0);
if(!QFile::exists(*(QString*)wdgt->idir+"\\gfd"))
elbl->setVisible(false);
glt->setContentsMargins(0,20,0,20);
vlt->addLayout(glt);
vlt->addStretch(1);
QHBoxLayout *hlt2=new QHBoxLayout;
hlt2->addWidget(ppb=new ppbttn,1,Qt::AlignLeft);
hlt2->addWidget(npb=new fpbttn("&Next"),0,Qt::AlignRight);
hlt2->addWidget(epb=new fpbttn("&Exit"),0,Qt::AlignRight);
vlt->addLayout(hlt2);
connect(dpb,SIGNAL(clicked()),this,SLOT(slotdpbclicked()));
connect(epb,SIGNAL(clicked()),wdgt,SLOT(close()));
connect(ppb,SIGNAL(clicked()),this,SLOT(slotppbclicked()));
connect(npb,SIGNAL(clicked()),this,SLOT(slotnpbclicked()));
}
void dirdevice::slotdpbclicked(){
debug("dirdevice::slotdbclicked")
QFile file(*(QString*)wdgt->idir);
*(QString*)wdgt->idir=QFileDialog::getExistingDirectory(wdgt,tr("open directory"),*(QString*)wdgt->idir,QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);
if(!((QString*)wdgt->idir)->isEmpty()){
led->setText(*(QString*)wdgt->idir);
if(!QFile::exists(*(QString*)wdgt->idir+"\\gfd"))
elbl->setVisible(false);
else
elbl->setVisible(true);
}
debug("~dirdevice::slotdbclicked")
}
void dirdevice::slotscbstatechanged(){
}
void dirdevice::unhide(){
debug("dirdevice::unhide")
tlbl->setVisible(true);
lbl->setVisible(true);
led->setVisible(true);
dpb->setVisible(true);
if(QFile::exists(*(QString*)wdgt->idir+"\\gfd"))
elbl->setVisible(true);
npb->setVisible(true);
ppb->setVisible(true);
epb->setVisible(true);
debug("~dirdevice::unhide")
}
void dirdevice::hide(){
debug("dirdevice::hide")
tlbl->hide();
lbl->hide();
led->hide();
dpb->hide();
elbl->hide();
npb->hide();
ppb->hide();
epb->hide();
debug("~dirdevice::hide")
}
