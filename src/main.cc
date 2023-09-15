#include "map.h"
#include "player.h"

#include <string>
#include <string_view>

#include "include/raylib.h"

using namespace pacman;

int main(void) {
  const int screenWidth = 500;
  const int screenHeight = 500;
  const char* title = "screen title";

  InitWindow(screenWidth, screenHeight, title);

  SetTargetFPS(60);

  Map map{};

  Player player(screenWidth, screenHeight);

  while (!WindowShouldClose()) {

    if (UP == *player.GetDir()) {
      player.GetPos()->y += 1.0f;
    } else if (DOWN == *player.GetDir()) {
      player.GetPos()->y -= 1.0f;
    } else if (LEFT == *player.GetDir()) {
      player.GetPos()->x -= 1.0f;
    } else if (RIGHT == *player.GetDir()) {
      player.GetPos()->x += 1.0f;
    }

    if (IsKeyDown(KEY_RIGHT)) {
      *player.GetDir() = RIGHT;
    } else if (IsKeyDown(KEY_LEFT)) {
      *player.GetDir() = LEFT;
    } else if (IsKeyDown(KEY_DOWN)) {
      *player.GetDir() = UP;
    } else if (IsKeyDown(KEY_UP)) {
      *player.GetDir() = DOWN;
    }
    //------------------------------------------------

    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawCircleV(*player.GetPos(), 10, DARKGRAY);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
