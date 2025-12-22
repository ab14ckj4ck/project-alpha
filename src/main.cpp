#include "raylib.h"
#include <memory>
#include <vector>

#include "world/world-objects.h"
#include "entities/troops.h"

void update(float dt) {
    if (IsKeyPressed(KEY_F11)) {
        ToggleFullscreen();
    }
}

void render() {
    BeginDrawing();
    ClearBackground(BLACK);

    DrawText(TextFormat("Window: %d x %d", GetScreenWidth(), GetScreenHeight()), 10, 10, 20, WHITE);

    EndDrawing();
}

void init_game_memories(std::unique_ptr<std::vector<Texture2D>>& gangster_sprites) {
    gangster_sprites->push_back(load_gangster_sprites()); //TODO Debug
}

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "Project Alpha");

    //TODO DEBUG SECTION BEGIN
    auto gangster_sprites = std::make_unique<std::vector<Texture2D>>();


    //TODO DEBUG SECTION END

    while(!WindowShouldClose()) {
        const float dt = GetFrameTime();
        update(dt);
        render();
    }

    CloseWindow();

    return 0;
}
