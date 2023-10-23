//
// Created by patrick on 10/23/23.
//

#include "Display.h"

Display::Display() {
    this->width = 1024;
    this->height = 768;
    this->disp = al_create_display(width, height);
}

ALLEGRO_DISPLAY *Display::getDisplayHandle() {
    return this->disp;
}

float Display::getHeight() {
    return this->height;
}

float Display::getWidth() {
    return this->width;
}
