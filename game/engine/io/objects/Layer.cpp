//
// Created by ekkel on 08-06-2026.
//

#include "Layer.h"

#include <cstring>

#include "Tile.h"


void Layer::setName(std::string name) {
    this->name = name;
}
std::string Layer::getName() {
    return this->name;
}

void Layer::setHeight(int height) {
    this->height = height;
}
int Layer::getHeight() const {
    return this->height;
}

void Layer::setX(const int x) {
    this->x = x;
}

void Layer::setY(int y) {
    this->y = y;
}

int Layer::getX() const {
    return this->x;
}

Tile * Layer::getTile(int x, int y) {
    Tile *tile = new Tile(x, y);
    tile->setTileGid(this->mapData[x][y]);
    return tile;
}

int Layer::getY() {
    return this->y;
}

int Layer::getWidth() const {
    return this->width;
}

void Layer::setOpacity(int opacity) {
    this->opacity = opacity;
}

int Layer::getOpacity() {
    return this->opacity;
}

bool Layer::isVisible() {
}

void Layer::setVisible(bool visible) {
    this->visible = visible;
}

void Layer::setWidth(const int width) {
    this->width = width;
}



