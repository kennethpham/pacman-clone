#include "player.h"

Player::Player(int width, int height) {
  _status = NORMAL;
  _dir = RIGHT;
  _pos = {(float)width / 2, (float)height / 2};
}
