//
// Created by florian on 12/25/25.
//

#ifndef PROJECT_ALPHA_SPRITES_H
#define PROJECT_ALPHA_SPRITES_H

#include <raylib.h>
#include <string>
#include "../entities/entity-types.h"

enum class TroopAnim {
    IDLE,
    WALK,
    SHOOT,
    SPECIAL
};

struct Sprite_Assets {
    Troop_Type type_;
    Texture2D idle_;
    Texture2D walk_;
    Texture2D shoot_;
    Texture2D special_;
};

void load_sprites(const std::string& filepath, Sprite_Assets* container);

Rectangle get_frame(int frame);

#endif //PROJECT_ALPHA_SPRITES_H
