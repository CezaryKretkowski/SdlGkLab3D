//
// Created by cezar on 16.01.2022.
//

#ifndef SDLGKLAB3D_RECTANGLE_H
#define SDLGKLAB3D_RECTANGLE_H
#include "../RenderableObject/RenderableObject.h"
#include "../Point3D.h"
#include "../Color.h"
#include <SDL2/SDL_opengl.h>
namespace Primitive {
    class Rectangle : public RenderableObject {
        float vertexPos[8][3];
        float width;
        float height;
        float depth;
        float color[3];

        void calculateVertex();

    public:
        Rectangle(float width = 0, float height = 0, float depth = 0, Point3D point = 0,Color c=0.f);

        void createRectangle(float width = 0, float height = 0, float depth = 0, Point3D point = 0,Color c=0.f);

        void draw();
        void scale(Point3D p);
        void rotate(Point3D p,float angle);
        void translate(Point3D p);

    };
}

#endif //SDLGKLAB3D_RECTANGLE_H
