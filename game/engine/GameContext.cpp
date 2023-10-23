//
// Created by patrick on 10/23/23.
//
#include <allegro5/allegro5.h>
#include <allegro5/allegro_ttf.h>
#include <allegro_primitives.h>
#include "GameContext.h"

GameContext::GameContext() {
    al_init();
    al_install_keyboard();
    al_init_ttf_addon();
    al_init_primitives_addon();
    this->timer = al_create_timer(1.0 / 30.0);
    this->queue = al_create_event_queue();
    this->display = new Display();
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(this->display->getDisplayHandle()));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    this->menu = new BottomMenu();
    this->menu->setContext(this);
    this->font = al_load_ttf_font("fonts/slkscre.ttf",20,0);
}


void GameContext::startMainLoop() {
    al_start_timer(timer);
    ALLEGRO_EVENT event;
    ALLEGRO_FONT* font = al_load_ttf_font("fonts/slkscre.ttf",40,0);
    bool redraw = true;
    while(1)
    {
        al_wait_for_event(queue, &event);

        if(event.type == ALLEGRO_EVENT_TIMER)
            redraw = true;
        else if((event.type == ALLEGRO_EVENT_KEY_DOWN) || (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE))
            break;

        if(redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_text(font, al_map_rgb(102, 51, 0), 0, 0, 0, "Hello world!");
            this->menu->draw();
            al_flip_display();
            redraw = false;
        }
    }
}

void GameContext::exit() {
 //   al_destroy_font(font);
    al_destroy_display(this->display->getDisplayHandle());
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
}

Display * GameContext::getDisplay() {
    return this->display;
}

ALLEGRO_FONT *GameContext::getFont() {
    return this->font;
}
