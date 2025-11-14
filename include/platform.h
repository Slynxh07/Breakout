#pragma once

#include "raylib.h"
#include "raymath.h"

class Platform {
public:
  Platform();
  void draw();
  void update();
  Rectangle getRect();

private:
  float width;
  float height;
  Vector2 pos;
  int speed;
  void move();
  Rectangle rect;
};
