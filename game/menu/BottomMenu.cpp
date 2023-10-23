//
// Created by patrick on 10/23/23.
//

#include "BottomMenu.h"
#include "../engine/GameContext.h"
#include "MenuBox.h"
#include <allegro_primitives.h>
#include <allegro_font.h>
#include <allegro_ttf.h>

using namespace std;
void BottomMenu::draw() {
   this->setBottomMenuHeight(250);
}

BottomMenu::BottomMenu() {

}

void BottomMenu::setContext(GameContext *gamecontext) {
    this->gameContext = gamecontext;
}

void BottomMenu::setBottomMenuHeight(float menuHeight) {

    MenuBox * menuBox = new MenuBox(this->gameContext,150);

    menuBox->addMenuItem("blurpking!");


    Display* display = this->gameContext->getDisplay();
    float width =  display->getWidth();
    float height = display->getHeight();
    float startX = 0;
    float startY = height-menuHeight-menuHeight;
    float endX = width;
    float endY = height;
  //  al_draw_line(startX, startY, endX, endY, al_map_rgb(102, 51, 0), 8.0f);
  //  al_draw_filled_rectangle(startX,startY,endX,endY, al_map_rgb(51, 51, 255));
}

void drawText() {

}

