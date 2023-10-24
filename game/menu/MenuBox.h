//
// Created by patrick on 10/23/23.
//

#include<list>

#ifndef GAME_MENUBOX_H
#define GAME_MENUBOX_H
using namespace std;
class GameContext;

class MenuBox {

private:
    list<char*> menuItems;
    GameContext * gameContext;

    int col = 0;
    int row = 0;

    float x1 = 0;
    float y1 = 0;

    float x2 = 0;
    float y2 = 0;

public:
    void setGameContext(GameContext* gameContext);
    MenuBox(GameContext *gameContext, float menuHeight);
    void addMenuItem(char * text);
};
#endif //GAME_MENUBOX_H
