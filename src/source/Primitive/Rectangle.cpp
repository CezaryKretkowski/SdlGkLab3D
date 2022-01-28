//
// Created by cezar on 16.01.2022.
//

#include <glm/vec4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../../headers/Primitive/Rectangle.h"
#include <iostream>
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


}
void Rectangle::rotate(Point3D p, float angle) {
    glm::mat4 matrix;
    matrix=glm::rotate(glm::radians(angle),glm::vec3 (p.getX(),p.getY(),p.getZ()));

    for(int i=0;i<8;i++){
        glm::vec4 v(vertexPos[i][0],vertexPos[i][1],vertexPos[i][2],0);
        glm::vec4 newVec= v*matrix;

        vertexPos[i][0]=newVec[0];
        vertexPos[i][1]=newVec[1];
        vertexPos[i][2]=newVec[2];
    }


}
void Rectangle::translate(Point3D p) {
    glm::mat4 matrix;
//    vertexPos[0][0]=p.getX();
//    vertexPos[0][1]=p.getY();
//    vertexPos[0][2]=p.getZ();
//    calculateVertex();
    matrix=glm::translate(glm::vec3 (p.getX(),p.getY(),p.getZ()));

    for(int i=0;i<8;i++){
        glm::vec4 v(1,vertexPos[i][0],vertexPos[i][1],vertexPos[i][2]);
        glm::vec4 newVec= v*matrix;

        vertexPos[i][0]=newVec[1];
        vertexPos[i][1]=newVec[2];
        vertexPos[i][2]=newVec[3];
    }
}
void Rectangle::scale(Point3D p) {
    glm::mat4 matrix;
    glm::mat4 matrix1;
    glm::mat4 matrix2;
    matrix1=glm::scale(glm::vec3 (p.getX(),p.getY(),p.getZ()));
    //matrix2=glm::scale(glm::vec3(-1));
    matrix=matrix1*matrix2;
    for(int i=0;i<8;i++){
        glm::vec4 v(vertexPos[i][0],vertexPos[i][1],vertexPos[i][2],1);
        glm::vec4 newVec= v*matrix;

        vertexPos[i][0]=newVec[0];
        vertexPos[i][1]=newVec[1];
        vertexPos[i][2]=newVec[2];
    }

}
