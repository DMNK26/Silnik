cmake_minimum_required(VERSION 4.0)
project(Silnik)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "C:/SFML-2.6.1/lib/cmake/SFML")
include_directories("C:/SFML-2.6.1/include")

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

file(GLOB SRC src/*.cpp)

include_directories(Silnik)

add_executable(Silnik
        Silnik/AnimatedObject.h
        Silnik/BitmapHandler.cpp
        Silnik/BitmapHandler.h
        Silnik/BitmapObject.h
        Silnik/CircleObject.cpp
        Silnik/CircleObject.h
        Silnik/DrawableObject.h
        Silnik/EllipseObject.cpp
        Silnik/EllipseObject.h
        Silnik/Engine.cpp
        Silnik/Engine.h
        Silnik/GameObject.h
        Silnik/LineObject.cpp
        Silnik/LineObject.h
        Silnik/LineSegment.cpp
        Silnik/LineSegment.h
        Silnik/Logger.cpp
        Silnik/Logger.h
        Silnik/main.cpp
        Silnik/Player.cpp
        Silnik/Player.h
        Silnik/Point2D.cpp
        Silnik/Point2D.h
        Silnik/PointObject.cpp
        Silnik/PointObject.h
        Silnik/PrimitiveRenderer.cpp
        Silnik/PrimitiveRenderer.h
        Silnik/RectangleObject.cpp
        Silnik/RectangleObject.h
        Silnik/ShapeObject.cpp
        Silnik/ShapeObject.h
        Silnik/SpriteObject.h
        Silnik/TransformableObject.h
        Silnik/TriangleObject.cpp
        Silnik/TriangleObject.h
        Silnik/UpdatableObject.h)

target_link_libraries(Silnik PRIVATE sfml-graphics sfml-window sfml-system)
