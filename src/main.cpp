#include "imgui.h"
#include "raylib.h"
#include "rlImGui.h"

int main() {
  InitWindow(1280, 960, "my_toy");
  SetTargetFPS(60);

  // 初始化 rlImGui（绑定 raylib 的渲染后端）
  rlImGuiSetup(true);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    rlImGuiBegin();
    ImGui::ShowDemoWindow();
    rlImGuiEnd();

    EndDrawing();
  }

  rlImGuiShutdown();
  CloseWindow();
  return 0;
}
