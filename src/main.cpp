#include "core/global_actor_array.h"

#include "raylib.h"
#include "rlImGui.h"

#include <iostream>
#include <ostream>

int main() {

  // Init
  InitWindow(720, 960, "my_toy");
  SetTargetFPS(60);
  rlImGuiSetup(true);

  if (const auto global_actor_array = std::make_unique<Global_actor_array>();
      !global_actor_array) {
    TraceLog(LOG_FATAL, "全局actor数组初始化失败\n");
    return 1;
  }

  TraceLog(LOG_INFO, "游戏初始化完成\n");
  // Loop
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
    // ImGui::ShowDemoWindow();
    rlImGuiEnd();

    EndDrawing();

    // Spawn & Cleanup
  }

  rlImGuiShutdown();
  CloseWindow();
  return 0;
}
