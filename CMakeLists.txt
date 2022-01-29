cmake_minimum_required(VERSION 3.20)
project(SdlGkLab3D)

set(CMAKE_CXX_STANDARD 14)
set(SDL2_INCLUDE_DIR ./dependencies/SDL2/include)
set(SDL2_LIB_DIR ./dependencies/SDL2/lib/x86)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})
find_package(OpenGL REQUIRED)
add_executable(SdlGkLab3D main.cpp src/headers/Engine.h src/source/Engine.cpp src/headers/KeyListener.h
        src/headers/MouseListener.h
        src/headers/Primitive/Rectangle.h
        src/source/Primitive/Rectangle.cpp src/headers/RenderableObject/RenderableObject.h
        src/headers/Point3D.h src/source/Point3D.cpp src/headers/Component.h src/headers/Primitive/PrimitiveRender.h src/headers/Color.h src/source/Primitive/PrimitiveRender.cpp src/headers/Observer.h src/source/Observer.cpp)
IF(WIN32)
target_link_libraries(${PROJECT_NAME} -lOpenGL32 SDL2main SDL2)
else()
    target_link_libraries(${PROJECT_NAME} -lOpenGL SDL2main SDL2)
    endif()
