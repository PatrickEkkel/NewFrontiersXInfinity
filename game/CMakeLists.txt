cmake_minimum_required(VERSION 3.26)
project(game)
INCLUDE_DIRECTORIES(/usr/include/allegro5)
LINK_DIRECTORIES(  /usr/lib/x86_64-linux-gnu)

set(CMAKE_CXX_STANDARD 17)

add_executable(game main.cpp)
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
        allegro)