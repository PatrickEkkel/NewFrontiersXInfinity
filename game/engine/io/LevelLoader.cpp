//
// Created by ekkel on 10-06-2026.
//
#include <fstream>
#include "LevelLoader.h"
#include "objects/Layer.h"
#include "objects/Tileset.h"
#include "objects/Level.h"
#include <json/json.h>



LevelLoader::LevelLoader() {
}

Level * LevelLoader::loadLevel(std::string filename) {
    Level * level = new Level();
    std::ifstream infile(filename);
    if (!infile) {
        errorMessage = "Can't Load level file";
        this->error = true;
    }
    Json::Value data;
    std::string errs;
    Json::CharReaderBuilder readerBuilder;
    Json::parseFromStream(readerBuilder, infile, &data, &errs);
    std::vector<Tileset> vec = {};
    const Json::Value& tilesets = data["tilesets"];
    const Json::Value& layers = data["layers"];

    for (const auto &layer: layers) {
        level->addLayer(new Layer(layer));
    }
    for (const auto& tileset : tilesets) {
        level->addTileset(new Tileset(tileset));
    }

    infile.close();
    return level;
}
