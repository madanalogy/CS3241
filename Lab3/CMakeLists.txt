cmake_minimum_required(VERSION 3.15)
project(Lab3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -framework GLUT -framework OpenGL")

include_directories(.)
include_directories(include)
include_directories(include/GL)
find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
endif()
file(COPY images DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(Lab3
        include/GL/eglew.h
        include/GL/freeglut.h
        include/GL/freeglut_ext.h
        include/GL/freeglut_std.h
        include/GL/glew.h
        include/GL/glut.h
        include/GL/glxew.h
        include/GL/wglew.h
        include/stb_image.h
        include/stb_image_write.h
        image_io.cpp
        image_io.h
        main.cpp)
