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
    public:
    MemoryManager() {
        this->bitmapLoader = new BitmapLoader();

    }
    NFX_Bitmap * loadBitmap(const string &fileName) {
        // TODO: this is bs of course, you can't load the bitmap and then look up ;-) its the other way around you dummy.
        NFX_Bitmap * result = this->bitmapLoader->loadBitmap(fileName);
        if (this->bitmapIndexMap.find(result->getBitmapId()) != this->bitmapIndexMap.end()) {
            return this->bitmaps[this->bitmapIndexMap[result->getBitmapId()]];
        } else {
            this->bitmaps.push_back(result);
        }
        return result;

    }
};


#endif //GAME_MEMORYMANAGER_H
