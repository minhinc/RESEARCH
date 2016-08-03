/*
 * treedevice.cpp
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
#include <QHeaderView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QLabel>
#include "widget.h"
#include "treedevice.h"
#include "fpbttn.h"
#include "debug.h"
treedevice::treedevice(device *p,device *n):device(p,n){
debug("treedevice::treedevice")
QHBoxLayout *hlt=new QHBoxLayout;
*(QString*)idstr=TREE;
vlt->addWidget(tlbl=new QLabel("<p><span style=\"font-size:14pt;font-family:'Tw Cen Mt';color:#00409e\">Select Components</span></p>"),0,Qt::AlignTop);
QGridLayout *glt=new QGridLayout;
glt->addWidget(albl=new QLabel("Please select the components you want to install."),0,0);
glt->addWidget(tw=new treewidget,1,0);
glt->addWidget(lbl=new QLabel("It would \ntake upto\n26 MB \ndisk space"),1,1,1,1,Qt::AlignTop);
glt->setContentsMargins(0,40,20,0);
tw->setColumnCount(1);
tw->header()->close();
QTreeWidgetItem *itm=new QTreeWidgetItem(tw);
itm->setText(0,"Qt Application");
itm->setCheckState(0,Qt::PartiallyChecked);
itm->setFlags(itm->flags() ^ Qt::ItemIsUserCheckable);
additem(itm,(void*)"bin",true);
additem(itm,(void*)"code",false,false);
tw->expandItem(itm);
glt->addWidget(dpb=new QPushButton("Default"),2,0,1,1,Qt::AlignLeft);
vlt->addLayout(glt);
vlt->addStretch(1);
hlt->addWidget(ppb=new ppbttn,1,Qt::AlignLeft);
hlt->addWidget(npb=new fpbttn("&Next"),0,Qt::AlignRight);
hlt->addWidget(epb=new fpbttn("&Exit"),0,Qt::AlignRight);
vlt->addLayout(hlt);
connect(ppb,SIGNAL(clicked()),this,SLOT(slotppbclicked()));
connect(npb,SIGNAL(clicked()),this,SLOT(slotnpbclicked()));
connect(epb,SIGNAL(clicked()),wdgt,SLOT(close()));
debug("~treedevice::treedevice")
}
void treedevice::unhide(){
debug("treedevice::unhide")
tw->setVisible(true);
tlbl->setVisible(true);
albl->setVisible(true);
lbl->setVisible(true);
dpb->setVisible(true);
npb->setVisible(true);
epb->setVisible(true);
ppb->setVisible(true);
debug("~treedevice::unhide")
}
void treedevice::hide(){
debug ("treedevice::hide")
tlbl->setVisible(false);
tw->setVisible(false);
albl->setVisible(false);
lbl->setVisible(false);
dpb->setVisible(false);
npb->setVisible(false);
npb->setVisible(false);
ppb->setVisible(false);
debug("~treedevice::hide")
}
void treedevice::additem(void* parent, void *str, bool disable,bool state){
debug("treedevice::treedevice")
QTreeWidgetItem *itm=new QTreeWidgetItem;
itm->setText(0,QString((const char*)str));
itm->setCheckState(0,Qt::CheckState(state));
if(disable)
itm->setFlags(itm->flags() ^ Qt::ItemIsUserCheckable);
((QTreeWidgetItem*)parent)->addChild(itm);
debug("treedevice::additem")
}
void treedevice::slotnpbclicked() {
debug("treedevice::slotnpbclicked")
wdgt->source=tw->topLevelItem(0)->child(1)->checkState(0);
debug("Check state"<<wdgt->source)
device::slotnpbclicked();
debug("~treedevice::slotnpbclicked")
}
