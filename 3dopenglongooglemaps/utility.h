/*
 * utility.h
 * Qt 3D OpenGL on Google Maps
 * Copyright (c) 2015-2016 Minh Inc www.minhinc.com
 *
 * This file is part of Qt3DOpenGLOnGoogleMaps
 *
 * Qt3DOpenGLOnGoogleMaps is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * Qt3DOpenGLOnGoogleMaps is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with Mgmp; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
#ifndef UTILITY_H
#define UTILITY_H
#define PI 3.1415926535
#define TIMEOUT 2000
#define ORTHOWHBT 140
class uc {
public:
 uc(){}
 uc(GLfloat x,GLfloat y,GLfloat z){data[0]=x;data[1]=y;data[2]=z;}
private:
 GLfloat data[3];
public:
 operator const GLfloat*() const{
  return data;
 }
 void drawcuboid(const uc bottomrightback, const uc bottomrightfront, const uc toprightback,
  const uc toprightfront, const uc topleftback, const uc topleftfront,
  const uc bottomleftback, const uc bottomleftfront, const uc colorwhole=uc(1.0,1.0,0.0));
 void drawcylinder(GLfloat radius1, GLfloat radius2, GLfloat yaxis1, GLfloat yaxis2, const uc colorfront=uc(1.0,1.0,0.0), 
  const uc colorback=uc(0.0,1.0,0.0), GLfloat beginangle=0.0, GLfloat endangle=2*PI, GLint SLICES=20);
 void drawcone(GLfloat radius, GLfloat yaxis1, GLfloat yaxis2, const uc colornose=uc(1.0,1.0,0.0), 
  const uc colorback=uc(0.0,1.0,0.0), GLfloat beginangle=0.0, GLfloat endangle=2*PI,GLint SLICES=20);
};
#endif
