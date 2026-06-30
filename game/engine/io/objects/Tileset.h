//
// Created by ekkel on 10-06-2026.
//

#ifndef GAME_TILESET_H
#define GAME_TILESET_H
#include <json/json.h>


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

    // TODO: rewrite this to store values in memory, this may be kind of slow ;-)

    int getFirstGid() {
        return jsonRef["firstgid"].asInt();
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
