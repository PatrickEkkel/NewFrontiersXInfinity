//
// Created by patrick on 10/23/23.
//

#include <color.h>

#include <allegro_primitives.h>
#include <allegro_font.h>
#include "MenuBox.h"
#include "../engine/GameContext.h"

MenuBox::MenuBox(GameContext *gameContext, float menuHeight) {

    this->gameContext = gameContext;
    Display* display = this->gameContext->getDisplay();
    float width =  display->getWidth();
    float height = display->getHeight();

    this->x1 = 5;
    this->y1 = height-menuHeight-menuHeight;

    this->x2 = width-5;
    this->y2 = height-5;

    al_draw_filled_rectangle(this->x1,this->y1,this->x2,this->y2, al_map_rgb(51, 51, 255));
    al_draw_rectangle(this->x1,this->y1,this->x2,this->y2, al_map_rgb(102, 255, 255),4.0f);
}

void MenuBox::setGameContext(GameContext *gameContext) {
    this->gameContext = gameContext;
}

void MenuBox::addMenuItem(char *text) {
    float xOffset = x1 + 5;
    float yOffset = y1 - 10;
    if(row > 13) {
        this->col++;
        this->row = 0;
    }
    xOffset = xOffset + (col*200);
    yOffset = yOffset + (20 * (row+1));
    al_draw_text(this->gameContext->getFont(), al_map_rgb(255, 255, 255), xOffset, yOffset, 0, text);
    this->menuItems.push_back(text);
    this->row++;
}
