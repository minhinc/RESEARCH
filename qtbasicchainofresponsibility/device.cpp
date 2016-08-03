/*
 * device.cpp
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
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QStringList>
#include "device.h"
#include "widget.h"
#include "debug.h"
widget* device::wdgt=NULL;
bool device::pbnext=true;
device::device(device *p,device *n):prev(p),next(n){
debug("device::device")
idstr=new QString;
vlt=new QVBoxLayout;
vlt->setContentsMargins(0,0,0,0);
debug("~device::device")
}
void device::work(){
int index=0;
debug("device::work")
while(index!=((QStringList*)wdgt->rlst)->size()){
if(((QStringList*)wdgt->rlst)->at(index)==*(QString*)identity()) break;
++index;
}
if(index<((QStringList*)wdgt->rlst)->size()){
wdgt->layout()->removeItem(wdgt->vlt);
((QHBoxLayout*)wdgt->layout())->insertLayout(1,vlt,1);
wdgt->vlt=vlt;
unhide();
}else
if(pbnext && next != 0){
hide();
next->work();
}else
if(!pbnext && prev !=0){
hide();
prev->work();
}
debug("~device::work")
}
void device::slotnpbclicked(){
debug("device::slotnpbclicked")
pbnext=true;
if(next!=NULL){
hide();
next->work();
}
debug("~device::slotnpbclicked")
}
void device::slotppbclicked(){
debug("device::slotppbclicked")
pbnext=false;
if(prev!=NULL){
hide();
prev->work();
}
debug("~device::slotppbclicked")
}
void* device::identity(){
debug("device::identity")
return (void*)idstr;
}
device::~device(){
debug("device::~device")
delete (QVBoxLayout*)vlt;
delete (QString*) idstr;
if(next != 0)
delete next;
debug("~device::~device")
}
