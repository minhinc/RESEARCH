/*
 * fpbttn.cpp
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
#include <QPainter>
#include <QPen>
#include "fpbttn.h"
#include "debug.h"
fpbttn::fpbttn(const QString& text,QWidget *p):QPushButton(text,p){
debug("fpbttn::fpbttn")
debug("~fpbttn::fpbttn")
}
QSize fpbttn::sizeHint() const{
return QSize(text().size()*10,BUTTON_HEIGHT);
}
ppbttn::ppbttn(QWidget *p):QPushButton(p){
debug("/ppbttn::ppbttn");
drawgreen=false;
}
void ppbttn::paintEvent(QPaintEvent* /*e*/){
QPen pen(Qt::Dense2Pattern,6,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
QPainter p(this);
if(drawgreen)
pen.setBrush(QColor("#004000"));
else
pen.setBrush(Qt::Dense2Pattern);
p.setPen(pen);
p.drawLine(4,rect().height()/2,10,rect().height()/2-10);
p.drawLine(4,rect().height()/2,10,rect().height()/2+10);
p.drawLine(4,rect().height()/2,20,rect().height()/2);
}
QSize ppbttn::sizeHint() const{
debug("/ppbttn::sizeHint")
return QSize(BUTTON_WIDTH,BUTTON_HEIGHT);
}
void ppbttn::enterEvent(QEvent* /*e*/){
drawgreen=true;
}
void ppbttn::leaveEvent(QEvent* /*e*/){
drawgreen=false;
}
treewidget::treewidget(QTreeWidget *p):QTreeWidget(p){}
QSize treewidget::sizeHint() const{
return QSize(100,20);
}
