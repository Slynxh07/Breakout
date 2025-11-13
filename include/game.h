#pragma once

#include "raylib.h"
#include "platform.h"
#include "ball.h"

class Game {
public:
  Game();
  void update();

private:
  void draw();
  Platform platform;
  Ball ball;
};
