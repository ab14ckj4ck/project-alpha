//
// Created by florian on 12/25/25.
//

#include "sprites.h"

void load_sprites(const std::string& filepath, Sprite_Assets* container) {
    const std::string idle_path = filepath + "_idle.png";
    const std::string walk_path = filepath + "_walk.png";
    const std::string shoot_path = filepath + "_shoot.png";
    const std::string special_path = filepath + "_special.png";

    Texture2D tex = LoadTexture(idle_path.c_str());
    SetTextureFilter(tex, TEXTURE_FILTER_POINT);
    container->idle_ = tex;

    tex = LoadTexture(walk_path.c_str());
    SetTextureFilter(tex, TEXTURE_FILTER_POINT);
    container->walk_ = tex;

    tex = LoadTexture(shoot_path.c_str());
    SetTextureFilter(tex, TEXTURE_FILTER_POINT);
    container->shoot_ = tex;

    tex = LoadTexture(special_path.c_str());
    SetTextureFilter(tex, TEXTURE_FILTER_POINT);
    container->special_ = tex;
}

Rectangle get_frame(int frame, const TroopAnim anim, const Sprite_Assets* assets, const int frame_count) {
    const Texture2D* tex = nullptr;
    if (frame_count <= 0) {
        return {0, 0, 0, 0}; // error -> empty texture
    }

    switch(anim) {
    case TroopAnim::IDLE: tex = &assets->idle_;
        break;
    case TroopAnim::WALK: tex = &assets->walk_;
        break;
    case TroopAnim::SHOOT: tex = &assets->shoot_;
        break;
    case TroopAnim::SPECIAL: tex = &assets->special_;
        break;
    default: return {0, 0, 0, 0}; // error -> empty texture
    }

    const float frame_w = tex->width / frame_count; // assuming 6 frames per animation
    const float frame_h = tex->height;

    frame %= frame_count; // loop around if frame exceeds number of frames

    return Rectangle
        {frame * frame_w, 0, frame_w, frame_h};
}
