#include "imgui.h"
#include "raylib.h"
#include "rlImGui.h"

#include <iostream>
#include <ostream>

int main() {
  InitWindow(720, 960, "my_toy");
  SetTargetFPS(60);

  // 初始化 rlImGui（绑定 raylib 的渲染后端）
  rlImGuiSetup(true);

  while (!WindowShouldClose()) {

    // Input
    if (const int key = GetKeyPressed()) {
      std::cout << "key: " << key << std::endl;
    }

    // Tick

    // Physics & Collision

    // Render
    BeginDrawing();
    ClearBackground(BLACK);

    rlImGuiBegin();
    ImGui::ShowDemoWindow();
    rlImGuiEnd();

    EndDrawing();

    // Spawn & Cleanup
  }

  rlImGuiShutdown();
  CloseWindow();
  return 0;
}
