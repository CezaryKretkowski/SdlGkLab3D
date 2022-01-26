//
// Created by cezar on 18.10.2021.
//
//#include "PrimitiveRenderer.h"
#include "../headers/Point3D.h"

Point3D::Point3D(float x, float y,float z){
    this->x=x;
    this->y=y;
    this->z=z;
}
void Point3D::creatPoint(float x, float y, float z) {
    this->x=x;
    this->y=y;
    this->z=z;
}
float Point3D::getX() {
    return this->x;
}
float Point3D::getY(){
    return this->y;
}
float Point3D::getZ() {
    return this->z;
}
void Point3D::setX(float x) {
    this->x=x;
}
void Point3D::setY(float y) {
    this->y=y;
}
void Point3D::setZ(float z) {
    this->z=z;
}
