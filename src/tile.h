#ifndef _PACMAN_TILE_H_
#define _PACMAN_TILE_H_

namespace pacman {

enum TILE_STATE {
  EMPTY = 0,
  WALL = 1,
  OCCUPIED = 2,
};

class Tile {
public:
  Tile();

  TILE_STATE* GetState() { return &_state; };

private:
  TILE_STATE _state{};
};

} // namespace pacman

#endif
