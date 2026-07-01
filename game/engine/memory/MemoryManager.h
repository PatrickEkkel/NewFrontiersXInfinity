//
// Created by ekkel on 29-06-2026.
//

#ifndef GAME_MEMORYMANAGER_H
#define GAME_MEMORYMANAGER_H
#include <vector>
#include <map>
#include "../primitives/NFX_Bitmap.h"
#include "../io/BitmapLoader.h"


using namespace std;
class MemoryManager {
    std::vector<NFX_Bitmap*> bitmaps = {};
    BitmapLoader * bitmapLoader;
    map<string, int> bitmapIndexMap;
    int lastIndex = 0;
    public:
    MemoryManager() {
        this->bitmapLoader = new BitmapLoader();

    }
    NFX_Bitmap * loadBitmap(const string &fileName) {
        filesystem::path bitmapId(fileName);
        if (this->bitmapIndexMap.find(bitmapId) != this->bitmapIndexMap.end()) {
            return this->bitmaps[this->bitmapIndexMap[bitmapId]];
        }
        NFX_Bitmap * result = this->bitmapLoader->loadBitmap(fileName);
        this->bitmapIndexMap[bitmapId] = this->lastIndex;
        this->bitmaps.push_back(result);
        this->lastIndex+= 1;
        return result;

    }
};


#endif //GAME_MEMORYMANAGER_H
