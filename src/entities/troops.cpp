//
// Created by florian on 12/19/25.
//

#include "troops.h"

std::string GANGSTER_ASSET = "../assets/textures/gangster_idle.png";


Troop spawn_soldier(const float x, const float y) {
    Troop t;

    t.type_ = Troop_Type::SOLDIER;
    t.ai_type_ = AI_Type::INFANTRY;
    t.special_ = Troop_Special::SANDBAGS;

    t.pos_ = {x, y};

    t.speed_ = SOLDIER_SPEED * UNIT; // speed in units
    t.range_ = SOLDIER_RANGE * UNIT; // range in units
    t.damage_ = SOLDIER_DAMAGE;
    t.health_ = 100.f;

    t.alive_ = true;
    t.does_special_ = false;
    t.selected_ = false;

    return t;
}

//TODO: DEBUG
Texture2D load_gangster_sprites() {
    const Texture2D gangster = LoadTexture(GANGSTER_ASSET.c_str());
    SetTextureFilter(gangster, TEXTURE_FILTER_POINT);

    return gangster;
}