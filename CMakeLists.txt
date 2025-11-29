cmake_minimum_required(VERSION 4.0)
project(Silnik)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "C:/SFML-2.6.1/lib/cmake/SFML")
include_directories("C:/SFML-2.6.1/include")

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

file(GLOB_RECURSE SRC CONFIGURE_DEPENDS
        Silnik/*.cpp
        Silnik/*.h)

include_directories(Silnik)

add_executable(Silnik ${SRC})


target_link_libraries(Silnik PRIVATE sfml-graphics sfml-window sfml-system)
