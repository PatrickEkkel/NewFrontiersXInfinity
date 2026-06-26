//
// Created by ekkel on 10-06-2026.
//

#ifndef GAME_TILESET_H
#define GAME_TILESET_H
#include <iostream>
#include <ostream>


class Tileset {
    Json::Value jsonRef;
    int columns = 0;
    int firstgid = 0;
    std::string imageName;
    public:
    explicit Tileset(const Json::Value& jsonRef) {
        this->jsonRef = jsonRef;
    }

    std::string getImageName() {
        return jsonRef["image"].asString();
    }

    int getImageHeight() {
        return jsonRef["imageheight"].asInt();
    }
    int getImageWidth() {
        return jsonRef["imagewidth"].asInt();
    }
    int getTileHeight() {
        return jsonRef["tileheight"].asInt();
    }
    int getTileWidth() {
        return jsonRef["tilewidth"].asInt();
    }

};


#endif //GAME_TILESET_H
