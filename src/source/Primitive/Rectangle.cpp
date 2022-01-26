//
// Created by cezar on 16.01.2022.
//

#include "../../headers/Primitive/Rectangle.h"
using namespace Primitive;
void Rectangle::calculateVertex() {
    this->vertexPos[1][0]=vertexPos[0][0];//1
    this->vertexPos[1][1]=vertexPos[0][1]-height;
    this->vertexPos[1][2]=vertexPos[0][2];

    this->vertexPos[2][0]=vertexPos[1][0]-width;//2
    this->vertexPos[2][1]=vertexPos[1][1];
    this->vertexPos[2][2]=vertexPos[1][2];

    this->vertexPos[3][0]=vertexPos[2][0];//3
    this->vertexPos[3][1]=vertexPos[2][1]+height;
    this->vertexPos[3][2]=vertexPos[2][2];

    this->vertexPos[4][0]=vertexPos[3][0];//4
    this->vertexPos[4][1]=vertexPos[3][1];
    this->vertexPos[4][2]=vertexPos[3][2]+depth;

    this->vertexPos[5][0]=vertexPos[4][0]+width;//5
    this->vertexPos[5][1]=vertexPos[4][1];
    this->vertexPos[5][2]=vertexPos[4][2];

    this->vertexPos[6][0]=vertexPos[5][0];//6
    this->vertexPos[6][1]=vertexPos[5][1]-height;
    this->vertexPos[6][2]=vertexPos[5][2];

    this->vertexPos[7][0]=vertexPos[6][0]-width;
    this->vertexPos[7][1]=vertexPos[6][1];
    this->vertexPos[7][2]=vertexPos[6][2];

}
Rectangle::Rectangle(float width, float height, float depth,Point3D point,Color c) {

    this->width=width;
    this->height=height;
    this->depth=depth;
    this->vertexPos[0][0]=point.getX();
    this->vertexPos[0][1]=point.getY();
    this->vertexPos[0][2]=point.getZ();
    calculateVertex();
    this->color[0]=color[0];
    this->color[1]=color[1];
    this->color[2]=color[2];
}
void Rectangle::createRectangle(float width, float height, float depth, Point3D point, Color c) {
    this->width=width;
    this->height=height;
    this->depth=depth;
    this->vertexPos[0][0]=point.getX();
    this->vertexPos[0][1]=point.getY();
    this->vertexPos[0][2]=point.getZ();
    calculateVertex();
    this->color[0]=color[0];
    this->color[1]=color[1];
    this->color[2]=color[2];
}
void Rectangle::draw() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_QUADS);

    glColor3f(color[0],color[1],color[2]);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3fv(vertexPos[0]);
    glVertex3fv(vertexPos[1]);
    glVertex3fv(vertexPos[2]);
    glVertex3fv(vertexPos[3]);

    glColor3f(0.0, 1.0, 0.0);
    glVertex3fv(vertexPos[3]);
    glVertex3fv(vertexPos[4]);
    glVertex3fv(vertexPos[7]);
    glVertex3fv(vertexPos[2]);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3fv(vertexPos[0]);
    glVertex3fv(vertexPos[5]);
    glVertex3fv(vertexPos[6]);
    glVertex3fv(vertexPos[1]);

    glColor3f(0.0, 1.0, 1.0);
    glVertex3fv(vertexPos[5]);
    glVertex3fv(vertexPos[4]);
    glVertex3fv(vertexPos[7]);
    glVertex3fv(vertexPos[6]);

    glColor3f(1.0, 1.0, 0.0);
    glVertex3fv(vertexPos[5]);
    glVertex3fv(vertexPos[0]);
    glVertex3fv(vertexPos[3]);
    glVertex3fv(vertexPos[4]);

    glColor3f(1.0, 0.0, 1.0);
    glVertex3fv(vertexPos[6]);
    glVertex3fv(vertexPos[1]);
    glVertex3fv(vertexPos[2]);
    glVertex3fv(vertexPos[7]);


    glEnd();

    glMatrixMode(GL_MODELVIEW);

}
