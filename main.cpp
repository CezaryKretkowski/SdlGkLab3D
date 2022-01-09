#include <iostream>
//#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <gl/gl.h>
#include <gl/glu.h>

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <gl/gl.h>
#include <SDL_opengl.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "src/headers/Engine.h"

class MainWindow:public KeyListener {
public:
    Engine engine;
    void onKeyPressedDown(SDL_Event e){
        if(e.key.keysym.sym=='s') {
            engine.clear(255.f,255.f,255.f,255.f);

        }

    }
};


int main (int ArgCount, char **Args)
{

      MainWindow *mainWindow=new MainWindow();

      mainWindow->engine.addKeyListener(mainWindow);
      mainWindow->engine.init("Grafika Komputerowa",100,100,800,600,SDL_WINDOW_OPENGL);
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
