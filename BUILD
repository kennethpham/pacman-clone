cc_binary(
  name = "pacman",
  srcs = ["src/main.cc"],
  data = glob(["resources/**"]),
  deps = [
    "@raysan5_raylib//:raylib",
    ":map",
    ":player",
  ],
)

cc_library(
  name = "map",
  srcs = ["src/map.cc"],
  hdrs = ["src/map.h"],
  deps = [":tile"],
)

cc_library(
  name = "tile",
  srcs = ["src/tile.cc"],
  hdrs = ["src/tile.h"],
)

cc_library(
  name = "player",
  srcs = ["src/player.cc"],
  hdrs = ["src/player.h"],
  deps = [
    "@raysan5_raylib//:raylib",
  ]
)

