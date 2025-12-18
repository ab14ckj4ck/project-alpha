#include "raylib.h"
#include "world/world-objects.h"

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
