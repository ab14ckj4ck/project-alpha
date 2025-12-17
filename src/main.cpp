#include "raylib.h"

int main() {
    InitWindow(800, 600, "Project Alpha");

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
