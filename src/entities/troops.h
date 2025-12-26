//
// Created by florian on 12/19/25.
//

#ifndef PROJECT_ALPHA_TROOPS_H
#define PROJECT_ALPHA_TROOPS_H

#include <raylib.h>

#include "entity-types.h"
#include "../world/world-objects.h"

inline float SOLDIER_SPEED = 1.f;
inline float SOLDIER_RANGE = 10.f;
inline float SOLDIER_DAMAGE = 1.f;

struct Troop {

    Troop_Type type_;
    AI_Type ai_type_;
    Troop_Special special_;

    Vector2 pos_;

    float speed_;
    float range_;
    float damage_;
    float health_;

    bool alive_;
    bool does_special_;
    bool selected_;
};

Troop spawn_soldier();

#endif //PROJECT_ALPHA_TROOPS_H