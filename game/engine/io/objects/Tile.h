//
// Created by ekkel on 27-06-2026.
//

#ifndef GAME_TILE_H
#define GAME_TILE_H
#include "Tileset.h"
#include <iostream>
#include <string>

using namespace std;
class Tile {

    int x = 0;
    int y = 0;
    int tileGid = 0;
    Tileset * tileset = NULL;
public:
    Tile(int x, int y) {
        this->x = x;
        this->y = y;
    }
    int getHeight() const;
    int getWidth() const;
    void setTileset(Tileset * tileset) {
        this->tileset = tileset;
    }
    Tileset * getTileset() {
        return this->tileset;
    }
    void setTileGid(int index) {
        this->tileGid = index;
    }
    int getTileGid() {
        return this->tileGid;
    }

    std::string toString() {
        return "Tile: { gid: " + to_string(this->tileGid)
        + " x: " + to_string(this->x)
        + " y: " + to_string(this->y)
        + " height: " + to_string(this->tileset->getTileHeight())
        + " width: " + to_string(this->tileset->getTileWidth()) + " }"; " } ";
    }
};


#endif //GAME_TILE_H
