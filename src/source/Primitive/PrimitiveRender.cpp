//
// Created by cezar on 24.01.2022.
//
#include <SDL2/SDL_opengl.h>
#include "../../headers/Primitive/PrimitiveRender.h"
void PrimitiveRender::drawPoint(Point3D p, Color color) {

    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(color.getR(), color.getG(), color.getB());
    glBegin (GL_POINTS);
    glVertex3f (p.getX(), p.getY(), p.getZ());
    glEnd ();

}
void PrimitiveRender::drawLine(Point3D p1, Point3D p2, Color color) {
   // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(color.getR(), color.getG(), color.getB());
    glBegin (GL_LINES);
    glVertex3f(p1.getX(),p1.getY(),p1.getZ());
    glVertex3f(p2.getX(),p2.getY(),p2.getZ());
    glEnd();
    glMatrixMode(GL_MODELVIEW);
}
void PrimitiveRender::drawLineSegment(std::list<Point3D> vertexList, Color color) {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(color.getR(), color.getG(), color.getB());
    glBegin(GL_LINE_STRIP);
    for(std::list<Point3D>::iterator i= vertexList.begin();i!=vertexList.end();i++){
        glVertex3f(i->getX(),i->getY(),i->getZ());
    }
    glEnd();
    glMatrixMode(GL_MODELVIEW);
}
void PrimitiveRender::drawLineCloseSegment(std::list<Point3D> vertexList, Color color) {
   // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(color.getR(), color.getG(), color.getB());
    glBegin(GL_LINE_LOOP);
    for(std::list<Point3D>::iterator i= vertexList.begin();i!=vertexList.end();i++){
        glVertex3f(i->getX(),i->getY(),i->getZ());
    }
    glEnd();
    glMatrixMode(GL_MODELVIEW);
}
void PrimitiveRender::drawTriangle(Point3D p1, Point3D p2, Point3D p3, Color color) {
   // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin (GL_TRIANGLES);
    glColor3f(color.getR(),color.getB(),color.getG());

    glVertex3f(p1.getX(),p1.getY(),p1.getZ());
    glVertex3f(p2.getX(),p2.getY(),p2.getZ());
    glVertex3f(p3.getX(),p3.getY(),p3.getZ());

    glEnd();
    glMatrixMode(GL_MODELVIEW);
    glFlush();
}

