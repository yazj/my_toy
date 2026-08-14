#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main() {
  InitWindow(1280, 960, "raygui - controls test suite");
  SetTargetFPS(60);

  bool showMessageBox = false;

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

    if (GuiButton(Rectangle{.x = 24, .y = 24, .width = 120, .height = 30},
                  "#191#Show Message"))
      showMessageBox = true;

    if (showMessageBox)

    {
      GuiMessageBox(Rectangle{.x = 85, .y = 70, .width = 500, .height = 200},
                    "#191#Message Box", "Hi! This is a message!", "Nice;Cool");

      if constexpr (constexpr int btnActive = -1; btnActive >= 0)
        showMessageBox = false;
    }

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
