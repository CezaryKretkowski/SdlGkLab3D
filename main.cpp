#include <iostream>
//#define SDL_MAIN_HANDLED
#include <SDL.h>

#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <glm/glm.hpp>
#include "src/headers/Engine.h"
#include "src/headers/MouseListener.h"
#include "src/headers/Component.h"
#include "src/headers/Primitive/Rectangle.h"
#include "src/headers/Primitive/PrimitiveRender.h"
#include "src/headers/Observer.h"
GLfloat lightAmb[] = {0.2f, 0.2f, 0.2f, 1.0f};
GLfloat lightDif[] = {0.8f, 0.8f, 0.8f, 1.0f};
GLfloat lightSpc[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat lightPos[] = {45.0f, 1024/720, 1.0f, 100.0f};
class MainWindow:public KeyListener,public MouseListener,public Component{
public:

    Engine engine;
    int myszkaX;
    int myszkaY;
    int width;
    int hight;

    std::list<Point3D> list;
    std::list<Point3D> list2;
    std::list<Point3D> list3;
    bool end=true;
    Primitive::Rectangle rect;
    Primitive::Rectangle rect1;
    Point3D p1;
    Point3D p2;
    Point3D p3;
    Point3D p4;
    Point3D p5;
    Color color;
    PrimitiveRender render;
    Observer obs;
    float angle;
    float  z,x,y;
    double time;


    void onKeyPressedDown(SDL_Event e){
        if(e.key.keysym.sym==SDL_KeyCode::SDLK_z){
            Point3D p(-1,-1,-1);
            rect.rotate(p,5);
            //rect.scale(p);
        }
        if(e.key.keysym.sym==SDL_KeyCode::SDLK_c){
            Point3D p(1,1,1);
            rect.rotate(p,5);
            //rect.scale(p);
        }
        if(e.key.keysym.sym==SDL_KeyCode::SDLK_e){
            angle++;
            Point3D p(1.0f,0.0f,0.0f);
            rect.translate(p);
            puts("s");
        }
        if(e.key.keysym.sym==SDL_KeyCode::SDLK_q){
            angle++;
            Point3D p(-1.0f,0.0f,0.0f);
            rect.translate(p);
            puts("s");
        }
    }
    void onMouseMotion(SDL_Event e){
        myszkaX = e.motion.x;
        myszkaY = e.motion.y;

    }
    void onMousePressed(SDL_Event e){
        if(SDL_BUTTON_LEFT==e.button.button){
            printf("pos x %d\n",myszkaX);
            printf("pos y %d\n",myszkaY);
        }
    }
    void run(Engine *super){
        Point3D p(0,0,0);
        Point3D p01(0.1,0.1,0);
        Point3D p02(2,0,0);
        Point3D p03(3,3,0);
        Point3D p04(-3,3,-0.5);
        Point3D p05(-3,4,-0.5);
        Point3D p06(-1,0,-0.5);
        Point3D p07(-3,0,-0.5);
        Point3D p08(1,0,-0.5);
        list2.push_front(p01);
        list2.push_front(p02);
        list2.push_front(p03);
        list3.push_front(p04);
        list3.push_front(p05);
        list3.push_front(p06);
        render.drawLineCloseSegment(list2,color);


       SDL_GL_MakeCurrent(super->getWindow(), super->getContext());
       SDL_GetWindowSize(super->getWindow(), &width, &hight);
       glViewport(0, 0, width, hight);

       render.drawPoint(p,color);
        rect.draw();
        rect1.draw();
        render.drawTriangle(p3,p4,p5,color);
        render.drawLineSegment(list3,color);
        render.drawLine(p07,p08,color);


        SDL_GL_SwapWindow(super->getWindow());
        list2.clear();
        list3.clear();
    }
    void setUp(Engine *super){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        this->p1.creatPoint(0.0f,0.0f, 20.0f);
        this->p2.creatPoint(0.0f,0.0f, 0.0f);

        this->p3.creatPoint(2.5,0.5,-2.5);
        this->p4.creatPoint(0.5,0.5,-2.5);
        this->p5.creatPoint(0.5,2.5,-2.5);
        this->color=Color(1.0f,1.0f,1.0f);
        this->list.push_front(p1);
        this->list.push_front(p2);
        this->list.push_front(p3);
        //engine.changeObserverOrto(-2.0, 2.0, -2.0, 2.0, -20.0, 20.0);
        engine.changeObserverPerspective(45.0f, 800/600, 1.0f, 100.0f);
      // engine.changeObserverOrto(-2.0, 2.0, -2.0, 2.0, -20.0, 20.0);
        this->rect.createRectangle(1.0f,1.0f,1.0f,p4,color);
        this->rect1.createRectangle(1.0f,1.0f,1.0f,p3,color);
        obs.move(p2);
        time=0;
        engine.addKeyListener(&obs);

    }


};


int main (int ArgCount, char **Args)
{
      char *title="Grafika Komputerowa";
      MainWindow *mainWindow=new MainWindow();
      mainWindow->engine.setLightParameters(lightAmb,lightDif,lightSpc,lightPos,Flat,true);
      mainWindow->engine.add(mainWindow);
      mainWindow->engine.addKeyListener(mainWindow);
      mainWindow->engine.addMouseListener(mainWindow);
      mainWindow->engine.init(title,100,100,1024,720,SDL_WINDOW_OPENGL,1);
    return 0;
}
