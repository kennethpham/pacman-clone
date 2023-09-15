#ifndef _PACMAN_PLAYER_H_
#define _PACMAN_PLAYER_H_

#include "include/raylib.h"
#include <deque>

namespace pacman {

enum STATUS {
  NORMAL = 0,
  INVINCIBLE = 1,
  DEAD = 2,
};

enum DIRECTION {
  UP = 0,
  DOWN = 1,
  LEFT = 2,
  RIGHT = 3,
};

class Player {
public:
  explicit Player(int width, int height);
  DIRECTION* GetDir() { return &_dir; };
  Vector2* GetPos() { return &_pos; };

private:
  STATUS _status{};
  DIRECTION _dir{};
  Vector2 _pos{};
};

} // namespace pacman

#endif
