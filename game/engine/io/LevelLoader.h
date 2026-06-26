//
// Created by ekkel on 10-06-2026.
//

#ifndef GAME_LEVELLOADER_H
#define GAME_LEVELLOADER_H
#include <string>
#include "../Level.h"


class LevelLoader {

    public:
    LevelLoader();
    Level * loadLevel(std::string filename);
};


#endif //GAME_LEVELLOADER_H
