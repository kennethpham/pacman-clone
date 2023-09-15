#ifndef _PACMAN_MAP_H_
#define _PACMAN_MAP_H_

#include "tile.h"

#include <array>

namespace pacman {

class Map {
public:
  Map(){};

  std::array<std::array<Tile, 5>, 5>* GetMap() { return &_map; };

private:
  std::array<std::array<Tile, 5>, 5> _map{};
};

} // namespace pacman

#endif
