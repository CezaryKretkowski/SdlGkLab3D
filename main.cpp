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

    void onKeyPressedDown(SDL_Event e){
        if(e.key.keysym.sym=='w') {
            engine.setLookAngle(engine.getLookAngle()+1.0);
            //engine.changeObserverPerspective();

        }
        if(e.key.keysym.sym=='s') {
            engine.setLookAngle(engine.getLookAngle()-1.0);

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
       Point3D p1(400.0,300.0, 0.0f);
       Point3D p2(340.0,215.0, 0.0f);
       Point3D p3(320.0,250.0, 0.0f);
       Point3D p4(0.5,0.5,-0.5);
       Color color(1.0f,1.0f,1.0f);
       list.push_front(p1);
       list.push_front(p2);
       list.push_front(p3);
       PrimitiveRender render;
       SDL_GL_MakeCurrent(super->getWindow(), super->getContext());
       SDL_GetWindowSize(super->getWindow(), &width, &hight);
       glViewport(0, 0, width, hight);
      // render.drawLine(p1,p2,color);
      render.drawLineCloseSegment(list,color);
     //render.drawTriangle(p1,p2,p3,color);

         engine.changeObservatorPos();
        SDL_GL_SwapWindow(super->getWindow());
        list.clear();
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
//    u32 WindowFlags = ;



    return 0;
}
