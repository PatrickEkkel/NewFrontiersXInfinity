//
// Created by ekkel on 29-06-2026.
//

#ifndef GAME_NFX_BITMAP_H
#define GAME_NFX_BITMAP_H
#include <bitmap.h>
#include <utility>
#include <string>


class NFX_Bitmap {
    ALLEGRO_BITMAP * allegro_bitmap = nullptr;
    std::string bitmapId;
    public:
    NFX_Bitmap(ALLEGRO_BITMAP * bitmap, std::string bitmapId) {
        this->allegro_bitmap = bitmap;
        this->bitmapId = std::move(bitmapId);
    };

    std::string getBitmapId() {
        return this->bitmapId;;
    }
};


#endif //GAME_NFX_BITMAP_H
