cmake_minimum_required(VERSION 3.15)
project(Lab4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)

add_executable(Lab4
        include/stb_image.h
        include/stb_image_write.h
        Camera.cpp
        Camera.h
        Color.h
        Image.cpp
        Image.h
        ImageIO.cpp
        ImageIO.h
        Light.h
        Main.cpp
        Material.h
        Plane.cpp
        Plane.h
        Ray.h
        Raytrace.cpp
        Raytrace.h
        Scene.h
        Sphere.cpp
        Sphere.h
        Surface.h
        Triangle.cpp
        Triangle.h
        Util.cpp
        Util.h
        Vector3d.h)
