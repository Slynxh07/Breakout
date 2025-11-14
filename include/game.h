#pragma once

#include "raylib.h"
#include "platform.h"
#include "ball.h"
#include "block.h"

class Game {
public:
  Game();
  void update();

private:
  void draw();
  void init();
  Platform platform;
  Ball ball;
  int rows;
  int cols;
  Block blocks[4][7];
};
