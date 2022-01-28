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
#include "src/headers/staticFunction.h"
#include "src/headers/Primitive/PrimitiveRender.h"
#include "src/headers/Observer.h"
class MainWindow:public KeyListener,public MouseListener,public Component{
public:

    Engine engine;
    int myszkaX;
    int myszkaY;
    int width;
    int hight;
    std::list<Point3D> list;
    bool end=true;
    Primitive::Rectangle rect;
    Primitive::Rectangle rect1;
    Point3D p1;
    Point3D p2;
    Point3D p3;
    Point3D p4;
    Color color;
    PrimitiveRender render;
    Observer obs;
    float  z,x,y;
    double time;
    double timeclaulate(){
        double lastTime=time;
        time=SDL_GetTicks();
        return (time-lastTime)/(float)SDL_GetPerformanceFrequency()*1000.0f;
    }

    void onKeyPressedDown(SDL_Event e){
        if(e.key.keysym.sym==SDL_KeyCode::SDLK_q){
            Point3D p(1,0,0);
            rect.rotate(p,0.9);
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

      time=timeclaulate();

       SDL_GL_MakeCurrent(super->getWindow(), super->getContext());
       SDL_GetWindowSize(super->getWindow(), &width, &hight);
       glViewport(0, 0, width, hight);

        rect.draw();
        rect1.draw();


        SDL_GL_SwapWindow(super->getWindow());

    }
    void setUp(Engine *super){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        this->p1.creatPoint(0.0f,0.0f, 20.0f);
        this->p2.creatPoint(0.0f,0.0f, 0.0f);
        this->p3.creatPoint(2.5,0.5,-2.5);
        this->p4.creatPoint(0.5,0.5,-2.5);
        this->color=Color(1.0f,1.0f,1.0f);
        this->list.push_front(p1);
        this->list.push_front(p2);
        this->list.push_front(p3);
        //engine.changeObserverOrto(-2.0, 2.0, -2.0, 2.0, -20.0, 20.0);
        engine.changeObserverPerspective(45.0f, 800/600, 1.0f, 100.0f);
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
      mainWindow->engine.add(mainWindow);
      mainWindow->engine.addKeyListener(mainWindow);
      mainWindow->engine.addMouseListener(mainWindow);
      mainWindow->engine.init(title,100,100,800,600,SDL_WINDOW_OPENGL,1);
    return 0;
}
