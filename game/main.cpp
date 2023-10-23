#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdbool.h>
#include <allegro_primitives.h>
#include "menu/BottomMenu.h"
#include "display/Display.h"
#include "engine/GameContext.h"

int main()
{
    GameContext* gameContext = new GameContext();
    gameContext->startMainLoop();
    /*
    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    */
    return 0;
}