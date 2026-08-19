#include "core/global_actor_array.h"

#include "actor/player/player.h"
#include "raylib.h"
#include "rlImGui.h"

#include <iostream>
#include <ostream>

int main() {

  // Init
  InitWindow(720, 960, "my_toy");
  SetTargetFPS(120);
  rlImGuiSetup(true);

  const Image icon =
      LoadImage("assets/MainShip/MainShip/Bases/PNGs/FullHealth.png");
  SetWindowIcon(icon);
  UnloadImage(icon);

  Global_actor_array &global_actor_array = Global_actor_array::get();
  auto &player = global_actor_array.spawn_actor<Player>(
      Vector2(360 - (45 * 1.5f) / 2, 800), 0, 1.5f,
      "assets/MainShip/MainShip/Bases/PNGs/FullHealth.png");

  TraceLog(LOG_INFO, "Game Init Finish");
  // Loop
  while (!WindowShouldClose()) {

    // Input
    if (IsKeyDown(65)) {
      player.move(Vector2(-1, 0));
    }
    if (IsKeyDown(68)) {
      player.move(Vector2(1, 0));
    }
    if (IsKeyDown(83)) {
      player.move(Vector2(0, 1));
    }
    if (IsKeyDown(87)) {
      player.move(Vector2(0, -1));
    }

    // Tick

    // Physics & Collision

    // Render
    BeginDrawing();
    ClearBackground(BLACK);

    global_actor_array.render();

    rlImGuiBegin();
    rlImGuiEnd();

    EndDrawing();

    // Spawn & Cleanup
    global_actor_array.clean_up();
  }

  rlImGuiShutdown();
  CloseWindow();
  return 0;
}
