//
// Created by ekkel on 08-06-2026.
//
#include <vector>
#include "Tileset.h"
#include "Layer.h"
#ifndef GAME_LEVEL_H
#define GAME_LEVEL_H


class Level {

private:
    int height = 0;

public:
    int getHeight();
    bool isInfinite();
    std::vector<Tileset> tilesets = {};
    std::vector<Layer> layers = {};

    void addTileset(Tileset * tileset) {
        tilesets.push_back(*tileset);
    }
    void addLayer(Layer * layer) {
        tilesets.push_back(*layer);
    }

};


#endif //GAME_LEVEL_H
