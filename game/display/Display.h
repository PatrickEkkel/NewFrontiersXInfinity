//
// Created by patrick on 10/23/23.
//

#ifndef GAME_DISPLAY_H
#define GAME_DISPLAY_H


#include <display.h>

class Display {
private:
    float width;
    float height;
    ALLEGRO_DISPLAY* disp;
public:
    ALLEGRO_DISPLAY* getDisplayHandle();
    float getWidth();
    float getHeight();
    Display();
};


#endif //GAME_DISPLAY_H
