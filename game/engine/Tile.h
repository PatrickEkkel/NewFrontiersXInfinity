//
// Created by ekkel on 27-06-2026.
//

#ifndef GAME_TILE_H
#define GAME_TILE_H


class Tile {
    int height = 0;
    int width = 0;
    int tileGid = 0;
public:
    Tile(int width, int height) {
        this->width = width;
        this->height = height;
    }
    int getHeight() const;

    int getWidth() const;
    void setTileGid(int index) {
        this->tileGid = index;
    }
    int getTileGid() {
        return this->tileGid;
    }
};


#endif //GAME_TILE_H
