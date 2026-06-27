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
    int getHeight();
    bool isInfinite();
    std::vector<Tileset> tilesets = {};
    std::vector<Layer> layers = {};

public:


    void addTileset(const Tileset * tileset) {
        this->tilesets.push_back(*tileset);
    }
    void addLayer(const Layer *  layer) {
        this->layers.push_back(*layer);
    }
    Tileset getTileSetByGID(int gid) {
        // TODO: hier was ik gebleven, selecteer de tileset op basis van de huidige tile

    }

    std::vector<Tileset> getTilesets() {
        return this->tilesets;
    }
    std::vector<Layer> getLayers() {
        return this->layers;
    }

};


#endif //GAME_LEVEL_H
