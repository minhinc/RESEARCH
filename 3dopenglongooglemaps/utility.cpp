/*
 * utility.cpp
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
#include <QGLWidget>
#include <QtCore/qmath.h>
#include "utility.h"

/*draw cuboid
                    +----------------------+ <--toprightback
                  /                      / |
               /                      /    |
 topleft    /                      /       |
 front--> +---------------------+          |
          |                     |          + <--bottomrightback
          |                     |        /
          |                     |     /
          |                     |  /
          +---------------------+
          ^
          | 
     bottomleftfront
*/
void uc::drawcuboid(const uc bottomrightback, const uc bottomrightfront, const uc toprightback,
 const uc toprightfront, const uc topleftback, const uc topleftfront,
 const uc bottomleftback, const uc bottomleftfront, const uc colorwhole) {
 glBegin(GL_QUAD_STRIP);
 glColor3fv(colorwhole);
 glVertex3fv(bottomrightback);
 glVertex3fv(bottomrightfront);
 glVertex3fv(toprightback);
 glVertex3fv(toprightfront);
 glVertex3fv(topleftback);
 glVertex3fv(topleftfront);
 glVertex3fv(bottomleftback);
 glVertex3fv(bottomleftfront);
 glEnd();
 glBegin(GL_QUADS);
 glVertex3fv(bottomrightfront);
 glVertex3fv(toprightfront);
 glVertex3fv(topleftfront);
 glVertex3fv(bottomleftfront);
 glVertex3fv(bottomrightback);
 glVertex3fv(toprightback);
 glVertex3fv(topleftback);
 glVertex3fv(bottomleftback);
 glEnd();
 }

/*draw a cylinder            radius1
                         -       |
                     -       -   |
                   -           - |
                  -      .......-v<-----yaxis1
                  -             - \
                   -           -    \
                    \-       -        \
                      \  -              \
                        \                 \
                          \                 \
                            \                 \
                              \                 \
                                \                 \
                                  \                 \
                                    \            -    \   radius2
                                      \      -        - \ |
                                        \  -            - |
                                          -      ........-v<----yaxis2
                                          -              -
                                           -            -
                                             -       -
                                                 -
*/
void uc::drawcylinder(GLfloat radius1, GLfloat radius2, GLfloat yaxis1, GLfloat yaxis2, const uc colorfront, 
 const uc colorback, GLfloat beginangle, GLfloat endangle, GLint SLICES) {
 GLfloat xval1=radius1*qCos(beginangle);
 GLfloat zval1=radius1*qSin(beginangle);
 GLfloat xval2=radius2*qCos(beginangle);
 GLfloat zval2=radius2*qSin(beginangle);
 GLfloat i=0;
 glBegin(GL_QUAD_STRIP);
 for(int count=1;count<=SLICES+1;count++) {
 glColor3fv(colorfront);
 glVertex3f(xval1,yaxis1,zval1);
 glColor3fv(colorback);
 glVertex3f(xval2,yaxis2,zval2);
 i+=(endangle-beginangle)/SLICES;
 xval1=radius1*qCos(beginangle+i);
 zval1=radius1*qSin(beginangle+i);
 xval2=radius2*qCos(beginangle+i);
 zval2=radius2*qSin(beginangle+i);
 }
 xval1=radius1*qCos(beginangle);
 zval1=radius1*qSin(beginangle);
 xval2=radius2*qCos(beginangle);
 zval2=radius2*qSin(beginangle);
 glColor3fv(colorfront);
 glVertex3f(xval1,yaxis1,zval1);
 glColor3fv(colorback);
 glVertex3f(xval2,yaxis2,zval2);
 glEnd();
 i=0;
 glBegin(GL_POLYGON);
 for(int count=1;count<=SLICES+1;count++) {
 glColor3fv(colorfront);
 glVertex3f(xval1,yaxis1,zval1);
 glColor3fv(colorback);
 glVertex3f(xval2,yaxis2,zval2);
 i+=(endangle-beginangle)/SLICES;
 xval1=radius1*qCos(beginangle+i);
 zval1=radius1*qSin(beginangle+i);
 xval2=radius2*qCos(beginangle+i);
 zval2=radius2*qSin(beginangle+i);
 }
 xval1=radius1*qCos(beginangle);
 zval1=radius1*qSin(beginangle);
 xval2=radius2*qCos(beginangle);
 zval2=radius2*qSin(beginangle);
 glColor3fv(colorfront);
 glVertex3f(xval1,yaxis1,zval1);
 glColor3fv(colorback);
 glVertex3f(xval2,yaxis2,zval2);
 glEnd();
}

/* draw cone
        nose---->   . <----yxais1
                    \ \
                     \  \
                      \   \
                       \    \
                        \     \
                         \      \
                          \       \
                           \        \
                            \         \
                             \          \
                              \           \
                               \            \
                                \             \
                                 \          -   \    radius
                                  \     -        -\     |
                                   \  -            -    |
                                    \-      ........-<---yaxis2
                                     -              -
                                      -            -
                                       -       -
                                           -
                     
*/
void uc::drawcone(GLfloat radius, GLfloat yaxis1, GLfloat yaxis2, const uc colornose, 
 const uc colorback, GLfloat beginangle, GLfloat endangle,GLint SLICES) {
 GLfloat xval=radius*qCos(beginangle);
 GLfloat zval=radius*qSin(beginangle);
 GLfloat i=(endangle-beginangle)/SLICES;
 glBegin(GL_TRIANGLE_FAN);
 for(int count=1;count<=SLICES;count++) {
 glColor3fv(colornose);
 glVertex3f(0,yaxis1,0);
 glColor3fv(colorback);
 glVertex3f(xval,yaxis2,zval);
 xval=radius*qCos(beginangle+i);
 zval=radius*qSin(beginangle+i);
 glColor3fv(colorback);
 glVertex3f(xval,yaxis2,zval);
 i+=(endangle-beginangle)/SLICES;
 }
 glColor3fv(colornose);
 glVertex3f(0,yaxis1,0);
 glColor3fv(colorback);
 glVertex3f(xval,yaxis2,zval);
 xval=radius*qCos(beginangle);
 zval=radius*qSin(beginangle);
 glColor3fv(colorback);
 glVertex3f(xval,yaxis2,zval);
 glEnd();
}

