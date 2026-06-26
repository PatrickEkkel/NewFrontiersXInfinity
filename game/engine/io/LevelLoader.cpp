//
// Created by ekkel on 10-06-2026.
//
#include <fstream>
#include "LevelLoader.h"
#include "../Layer.h"
#include "../Tileset.h"
#include "../Level.h"
#include <json/json.h>


LevelLoader::LevelLoader() {
}

Level * LevelLoader::loadLevel(std::string filename) {
    Level * level = new Level();
    std::ifstream infile(filename);
    Json::Value data;
    std::string errs;
    Json::CharReaderBuilder readerBuilder;
    Json::parseFromStream(readerBuilder, infile, &data, &errs);
    std::vector<Tileset> vec = {};
    const Json::Value& tilesets = data["tilesets"];
    const Json::Value& layers = data["layers"];

    for (const auto& layer : layers) {
        auto * newLayer = new Layer(layer);
    }
    for (const auto& tileset : tilesets) {
        auto * newTileset = new Tileset(tileset);
        vec.push_back(*newTileset);
    }

    infile.close();
    return level;
}
