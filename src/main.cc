#include "map.h"
#include "player.h"

#include <string>
#include <string_view>

#include "include/raylib.h"

using namespace pacman;

constexpr Vector2 tile_size = {100, 100};
constexpr int screen_width = 500;
constexpr int screen_height = 500;
const char* window_title = "screen title";
const char* player_image = "resources/player.png";

int main(void) {

  InitWindow(screen_width, screen_height, window_title);

  SetTargetFPS(60);

  Map map{};

  Player player(screen_width, screen_height);

  Image player_img = LoadImage(player_image);
  ImageResize(&player_img, 100, 100);
  // Default faces right.
  Texture2D player_r_texture = LoadTextureFromImage(player_img);
  // Rotate clock-wise, facing down.
  ImageRotateCW(&player_img);
  Texture2D player_d_texture = LoadTextureFromImage(player_img);
  // Rotate clock-wise, facing left.
  ImageRotateCW(&player_img);
  Texture2D player_l_texture = LoadTextureFromImage(player_img);
  // Rotate clock-wise, facing up.
  ImageRotateCW(&player_img);
  Texture2D player_u_texture = LoadTextureFromImage(player_img);
  UnloadImage(player_img);

  Texture2D* player_texture = &player_r_texture;

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
      player_texture = &player_r_texture;
    } else if (IsKeyDown(KEY_LEFT)) {
      *player.GetDir() = LEFT;
      player_texture = &player_l_texture;
    } else if (IsKeyDown(KEY_DOWN)) {
      *player.GetDir() = UP;
      player_texture = &player_d_texture;
    } else if (IsKeyDown(KEY_UP)) {
      *player.GetDir() = DOWN;
      player_texture = &player_u_texture;
    }

    BeginDrawing();

    ClearBackground(RAYWHITE);

    for (unsigned int i = 0; i < map.GetMap()->size(); ++i) {
      for (unsigned int j = 0; j < map.GetMap()->at(i).size(); ++j) {
        DrawRectangleV({(float)screen_width / map.GetMap()->size() * i,
                        (float)screen_height / map.GetMap()->at(i).size() * j},
                       tile_size, DARKBLUE);
      }
    }

    DrawTextureV(*player_texture, *player.GetPos(), WHITE);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
