//
// Created by cezar on 22.01.2022.
//

#ifndef SDLGKLAB3D_PRIMITIVERENDER_H
#define SDLGKLAB3D_PRIMITIVERENDER_H

#include <list>
#include "../Point3D.h"
#include "../Color.h"
class PrimitiveRender{
public:
    void drawPoint(Point3D p,Color color);
    void drawLine(Point3D p1,Point3D p2,Color color);
    void drawLineSegment(std::list<Point3D> vertexList,Color color);
    void drawLineCloseSegment(std::list<Point3D> vertexList,Color color);
    void drawTriangle(Point3D p1,Point3D p2,Point3D p3,Color color);
};
#endif //SDLGKLAB3D_PRIMITIVERENDER_H
