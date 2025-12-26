#include <iostream>

#include "raylib.h"
#include <memory>
#include <ostream>
#include <vector>
#include <map>

#include "render/sprites.h"


std::vector<Sprite_Assets> sprite_assets;

std::map<Troop_Type, std::string> TROOP_ASSET_PATH = {
    {Troop_Type::GANGSTER,  "gangster"},
    {Troop_Type::SOLDIER,   "soldier"},
    {Troop_Type::SNIPER,    "sniper"},
    {Troop_Type::SPECIAL_FORCES,    "special_forces"},
    {Troop_Type::ENGINEER,  "engineer"}
};

void create_troop_assets(const Troop_Type type) {
    for (const auto& t : sprite_assets) {
        if(t.type_ == type) return; // already loaded
    }

    Sprite_Assets asset;
    asset.type_ = type;
    std::string path = "../../assets/textures/";

    const auto it = TROOP_ASSET_PATH.find(type);
    if (it == TROOP_ASSET_PATH.end()) {
        std::cerr << "Unknown troop type" << std::endl; //TODO logging
        return; // error -> unknown type
    }

    path += it->second;;
    load_sprites(path, &asset);
    sprite_assets.push_back(asset);
}

void update(float dt) {
    if(IsKeyPressed(KEY_F11)) {
        ToggleFullscreen();
    }
}

void render() {
    BeginDrawing();
    ClearBackground(BLACK);

    DrawText(TextFormat("Window: %d x %d", GetScreenWidth(), GetScreenHeight()), 10, 10, 20, WHITE);

    EndDrawing();
}

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "Project Alpha");

    while(!WindowShouldClose()) {
        const float dt = GetFrameTime();
        update(dt);
        render();
    }

    CloseWindow();

    return 0;
}
