cmake_minimum_required(VERSION 3.26)
project(game)
INCLUDE_DIRECTORIES(/usr/include/allegro5 /usr/include/json)
LINK_DIRECTORIES(  /usr/lib/x86_64-linux-gnu)

set(CMAKE_CXX_STANDARD 17)
#find_package(jsoncpp REQUIRED)
add_executable(game main.cpp
        menu/BottomMenu.cpp
        menu/BottomMenu.h
        display/Display.cpp
        display/Display.h
        engine/GameContext.cpp
        engine/GameContext.h
        menu/MenuBox.cpp
        menu/MenuBox.h
        engine/io/objects/Level.cpp
        engine/io/objects/Level.h
        engine/io/objects/Layer.cpp
        engine/io/objects/Layer.h
        engine/io/LevelLoader.cpp
        engine/io/LevelLoader.h
)
TARGET_LINK_LIBRARIES(game
        allegro_acodec
        allegro_audio
        allegro_color
        allegro_dialog
        allegro_image
        allegro_main
        allegro_memfile
        allegro_physfs
        allegro_primitives
        allegro_ttf
        allegro_font
        allegro
        jsoncpp)