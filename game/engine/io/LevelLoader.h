//
// Created by ekkel on 10-06-2026.
//

#ifndef GAME_LEVELLOADER_H
#define GAME_LEVELLOADER_H
#include <string>
#include "../Level.h"


class LevelLoader {
private:
std::string errorMessage = "";
bool error = false;
public:
    LevelLoader();
    Level * loadLevel(std::string filename);
    std::string getErrorMessage() {
        return errorMessage;
    }
    [[nodiscard]] bool hasError() const {
        return this->error;
    }
};


#endif //GAME_LEVELLOADER_H
