//
// Created by patrick on 10/23/23.
//

#ifndef GAME_BOTTOMMENU_H
#define GAME_BOTTOMMENU_H


#include "../display/Display.h"

class GameContext;

class BottomMenu {


private:
    GameContext* gameContext;
    void setBottomMenuHeight(float height);
    void drawMenuText(char * text);
public:
    void setContext(GameContext * gamecontext);
    BottomMenu();
    void draw();
};


#endif //GAME_BOTTOMMENU_H
