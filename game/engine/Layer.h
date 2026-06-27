//
// Created by ekkel on 08-06-2026.
//

#ifndef GAME_LAYER_H
#define GAME_LAYER_H
#include <iostream>
#include <vector>

#include <string>
#include <value.h>


class Tile;

class Layer {

    Json::Value jsonRef;
    int height = 0;
    int width = 0;
    int opacity = 0;
    bool visible = false;
    int x = 0;
    int y = 0;
    std::string name;
    Json::Value jsonMapData;
    std::vector<std::vector<int>> mapData;


public:
        explicit Layer(const Json::Value& jsonRef) {
            this->jsonRef = jsonRef;
            this->name = jsonRef["name"].asString();
            this->height = jsonRef["height"].asInt();
            this->width = jsonRef["width"].asInt();
            this->jsonMapData = jsonRef["data"];
            this->mapData.resize(this->height);
            int offset = 0;
            for (int _y=0;_y<this->getHeight();_y++) {
                this->mapData[_y].resize(this->getWidth());
                offset = this->getWidth()*_y;
                for (int _x=0;_x<this->getWidth();_x++) {
                    this->mapData[_y][_x] = jsonMapData[offset+_x].asInt();
                }
            }
        }
        int* getData();
        Tile * getTile(int x, int y);
        void setHeight(int height);
        void setName( std::string name);
        std::string getName();
        int getHeight() const;
        void setWidth(int width);
        int getWidth() const;
        void setOpacity(int opacity);
        int getOpacity();
        bool isVisible();
        void setVisible(bool visible);
        void setX(int x);
        void setY(int y);
        int getX() const;
        int getY();


};


#endif //GAME_LAYER_H
