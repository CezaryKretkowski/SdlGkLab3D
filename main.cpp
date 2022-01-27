#include <iostream>
//#define SDL_MAIN_HANDLED
#include <SDL.h>

#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "src/headers/Engine.h"
#include "src/headers/MouseListener.h"
#include "src/headers/Component.h"
#include "src/headers/Primitive/Rectangle.h"
#include "src/headers/staticFunction.h"
#include "src/headers/Primitive/PrimitiveRender.h"

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
    Point3D p1;
    Point3D p2;
    Point3D p3;
    Point3D p4;
    Color color;
    PrimitiveRender render;

    void onKeyPressedDown(SDL_Event e){
        if(e.key.keysym.sym=='w') {
            engine.setLookAngle(engine.getLookAngle()+1.0);
            //engine.changeObserverPerspective();

        }
        if(e.key.keysym.sym=='s') {
            engine.setLookAngle(engine.getLookAngle()-1.0);

        }
        if(e.key.keysym.sym=='f') {
            if(end)
            {
                end=false;
                engine.endTask();
                puts("800/600");
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                engine.changeObserverOrto(0.0, 800, 600, 0.0, -1.0, 1.0);
                engine.reload();

            }else{
                end=true;
                engine.endTask();

                puts("2/-2");
                engine.changeObserverOrto(-2.0, 2.0, -2.0, 2.0, -20.0, 20.0);
                engine.reload();
            }

            //engine.changeObserverPerspective();

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



       SDL_GL_MakeCurrent(super->getWindow(), super->getContext());
       SDL_GetWindowSize(super->getWindow(), &width, &hight);
       glViewport(0, 0, width, hight);
      // render.drawLine(p1,p2,color);
      if(end)
      rect.draw();
       // render.drawLineCloseSegment(list,color);
      //else

     //render.drawTriangle(p1,p2,p3,color);

         engine.changeObservatorPos();
        SDL_GL_SwapWindow(super->getWindow());

    }
    void setUp(Engine *super){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        this->p1.creatPoint(400.0,300.0, 0.0f);
        this->p2.creatPoint(340.0,215.0, 0.0f);
        this->p3.creatPoint(320.0,250.0, 0.0f);
        this->p4.creatPoint(0.5,0.5,-0.5);
        this->color=Color(1.0f,1.0f,1.0f);
        this->list.push_front(p1);
        this->list.push_front(p2);
        this->list.push_front(p3);
        this->rect.createRectangle(1.0f,1.0f,1.0f,p4,color);
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
