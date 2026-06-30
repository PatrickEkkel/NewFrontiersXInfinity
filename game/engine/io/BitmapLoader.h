//
// Created by ekkel on 29-06-2026.
//

#ifndef GAME_BITMAPLOADER_H
#define GAME_BITMAPLOADER_H
#include <bitmap.h>
#include <bitmap_io.h>
#include <filesystem>
#include <string>
#include "../primitives/NFX_Bitmap.h"


using namespace std;

class BitmapLoader {

    public:

    NFX_Bitmap * loadBitmap(const std::string & fileName) {
        ALLEGRO_BITMAP *my_bitmap = al_load_bitmap(fileName.c_str());
        filesystem::path p(fileName);
        NFX_Bitmap * bitmap = new NFX_Bitmap(my_bitmap,p);
        return bitmap;
    }

};


#endif //GAME_BITMAPLOADER_H
