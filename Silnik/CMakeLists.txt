cmake_minimum_required(VERSION 3.15)
project(MyGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- SFML ----
find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

# ---- èrÛd≥a projektu ----
file(GLOB SRC src/*.cpp)

add_executable(MyGame ${SRC})

target_link_libraries(MyGame PRIVATE sfml-graphics sfml-window sfml-system)

# ---- Kopiowanie folderu assets ----
add_custom_command(
    TARGET MyGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/assets
            ${CMAKE_CURRENT_BINARY_DIR}/assets
)
