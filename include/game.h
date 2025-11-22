#pragma once

#include "raylib.h"
#include "platform.h"
#include "ball.h"
#include "block.h"
#include "brickHit.h"
#include <string>

class Game {
public:
  Game();
  void update();

private:
  void draw();
  void init();
  void restartGame();
  bool winCheck();
  void checkBrickCollision();
  Platform platform;
  Ball ball;
  int rows;
  int cols;
  bool running;
  Block blocks[4][7];
  std::string gameOverMessage;
};