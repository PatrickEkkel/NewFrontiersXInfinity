//
// Created by patrick on 10/23/23.
//

#ifndef GAME_GAMECONTEXT_H
#define GAME_GAMECONTEXT_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro_primitives.h>
#include "../display/Display.h"
#include "../menu/BottomMenu.h"
#include "memory/MemoryManager.h"

class GameContext {

private:
    ALLEGRO_TIMER* timer;
    ALLEGRO_EVENT_QUEUE* queue;
    Display* display;
    MemoryManager* memory;
    BottomMenu* menu;
    ALLEGRO_FONT * font;

public:
    GameContext();
    void initLib();
    void startMainLoop();
    Display * getDisplay();
    ALLEGRO_FONT * getFont();
    void exit();
};


#endif //GAME_GAMECONTEXT_H
