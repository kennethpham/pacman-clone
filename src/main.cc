#include "map.h"
#include "player.h"

#include <string>
#include <string_view>

#include "include/raylib.h"

using namespace pacman;

constexpr int screen_width = 500;
constexpr int screen_height = 500;
const char* window_title = "screen title";
const char* player_image = "resources/player.png";

int main(void) {

  InitWindow(screen_width, screen_height, window_title);

  SetTargetFPS(60);

  Map map{};

  Player player(screen_width, screen_height);

  while (!WindowShouldClose()) {

    if (UP == *player.GetDir()) {
      player.GetPos()->y += 1.0f;
      if (player.GetPos()->y > screen_height) {
        player.GetPos()->y = 0;
      }
    } else if (DOWN == *player.GetDir()) {
      player.GetPos()->y -= 1.0f;
      if (player.GetPos()->y < 0) {
        player.GetPos()->y = screen_height;
      }
    } else if (LEFT == *player.GetDir()) {
      player.GetPos()->x -= 1.0f;
      if (player.GetPos()->x < 0) {
        player.GetPos()->x = screen_width;
      }
    } else if (RIGHT == *player.GetDir()) {
      player.GetPos()->x += 1.0f;
      if (player.GetPos()->x > screen_width) {
        player.GetPos()->x = 0;
      }
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

    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawCircleV(*player.GetPos(), 10, DARKGRAY);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
