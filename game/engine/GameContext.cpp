//
// Created by patrick on 10/23/23.
//
#include <fstream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro_primitives.h>
#include "GameContext.h"

#include <iostream>
#include <json/json.h>

#include "io/objects/Layer.h"
#include "io/objects/Tile.h"
#include "io/objects/Tileset.h"
#include "io/LevelLoader.h"

using namespace std;

GameContext::GameContext() {
    al_init();
    al_init_image_addon();
    al_install_keyboard();
    al_init_ttf_addon();
    al_init_primitives_addon();
    this->memory = new MemoryManager();
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

    auto * levelLoader = new LevelLoader();
    auto * level = levelLoader->loadLevel("/home/ekkel/Git/NewFrontiersXInfinity/game/levels/tiled/test.tmj");
    std::string name = "Jup";
    string tilesetBasedir = "/home/ekkel/Git/NewFrontiersXInfinity/game_tilesets/";
    ALLEGRO_BITMAP *my_bitmap = al_load_bitmap("/home/ekkel/Git/NewFrontiersXInfinity/game_tilesets/sds_1.bmp");
    while(true)
    {
        al_wait_for_event(queue, &event);

        if(event.type == ALLEGRO_EVENT_TIMER)
            redraw = true;
        else if((event.type == ALLEGRO_EVENT_KEY_DOWN) || (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE))
            break;


        if(redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            //al_draw_bitmap(my_bitmap, 0, 0, 0);
            if (levelLoader->hasError()) {
                std::string errorMessage = levelLoader->getErrorMessage();
                al_draw_text(font, al_map_rgb(102, 51, 0), 0, 0, 0, errorMessage.c_str());
            }
            for ( auto& layer : level->getLayers()) {
                for (int x =0;x<layer.getWidth();x++) {
                    for (int y =0;y<layer.getHeight();y++) {
                        // std::cout <<  layer.getTile(x,y) << std::endl;

                        Tile * tile = layer.getTile(x, y);
                        tile->setTileset(level->getTileSetByGID(tile->getTileGid()));
                        if (tile->getTileGid()) {
                            string tilesetBitmapFilePath = tilesetBasedir + tile->getTileset()->getImageName();
                            this->memory->loadBitmap(tilesetBitmapFilePath);
                            //ALLEGRO_BITMAP *my_bitmap = al_load_bitmap("/home/ekkel/Git/NewFrontiersXInfinity/game_tilesets/sds_1.bmp");
                        }
                        // draw the tile on screen.. with al bitmap.. or something..

                        // calculate tile offset and retrieve tileset.
                    }
                }
            }
            al_draw_text(font, al_map_rgb(102, 51, 0), 0, 50, 0, name.c_str());
            //this->menu->draw();
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
