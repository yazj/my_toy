#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main() {
  InitWindow(1280, 960, "");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLACK);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
