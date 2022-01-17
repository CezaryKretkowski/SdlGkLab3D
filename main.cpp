#include <iostream>
//#define SDL_MAIN_HANDLED
#include <SDL.h>

#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "src/headers/Engine.h"
#include "src/headers/MouseListener.h"

class MainWindow:public KeyListener,public MouseListener{
public:
    Engine engine;
    int myszkaX;
    int myszkaY;
    void onKeyPressedDown(SDL_Event e){
        if(e.key.keysym.sym=='w') {
            engine.setLookAngle(engine.getLookAngle()+1.0);
            puts("dziala");
        }
        if(e.key.keysym.sym=='s') {
            engine.setLookAngle(engine.getLookAngle()-1.0);
            puts("dziala");
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
};


int main (int ArgCount, char **Args)
{

      MainWindow *mainWindow=new MainWindow();

      mainWindow->engine.addKeyListener(mainWindow);
      //mainWindow->engine.addMouseListener(mainWindow);
      mainWindow->engine.init("Grafika Komputerowa",100,100,800,600,SDL_WINDOW_OPENGL,1);
//    u32 WindowFlags = ;
////    SDL_Window *Window = SDL_CreateWindow("OpenGL Test", 100, 100, WinWidth, WinHeight, WindowFlags);
////    //assert(Window);
////    SDL_GLContext Context = SDL_GL_CreateContext(Window);
////
////    b32 Running = 1;
////    b32 FullScreen = 0;
////    while (Running)
////    {
////        SDL_Event Event;
////        while (SDL_PollEvent(&Event))
////        {
////            if (Event.type == SDL_KEYDOWN)
////            {
////                switch (Event.key.keysym.sym)
////                {
////                    case SDLK_ESCAPE:
////                        Running = 0;
////                        break;
////                    case 'f':
////                        FullScreen = !FullScreen;
////                        if (FullScreen)
////                        {
////                            SDL_SetWindowFullscreen(Window, WindowFlags | SDL_WINDOW_FULLSCREEN_DESKTOP);
////                        }
////                        else
////                        {
////                            SDL_SetWindowFullscreen(Window, WindowFlags);
////                        }
////                        break;
////                    default:
////                        break;
////                }
////            }
////            else if (Event.type == SDL_QUIT)
////            {
////                Running = 0;
////            }
////        }
////
////        glViewport(0, 0, WinWidth, WinHeight);
////        glClearColor(1.f, 0.f, 1.f, 0.f);
////        glClear(GL_COLOR_BUFFER_BIT);
////
////        SDL_GL_SwapWindow(Window);
////    }



    return 0;
}
