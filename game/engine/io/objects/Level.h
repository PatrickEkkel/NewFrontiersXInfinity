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
    Tileset * getTileSetByGID(int gid) {
        int nextTilesetGid = 0;
        Tileset * result = nullptr;
        auto itr = this->tilesets.begin();
        int currentPosition = 1;
        for (Tileset& tileset : tilesets) {
            // check if there is another tileset.
            if (this->tilesets.size() > currentPosition ) {
                nextTilesetGid = (itr + 1)->getFirstGid();
                if (gid > currentPosition && gid < nextTilesetGid) {
                    // select this tileset
                    result = &tileset;
                    break;
                }
            } else {
                // there is only 1 tileset.
                result = &tileset;
                break;
            }
        }
        return result;
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
