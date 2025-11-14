#include "platform.h"

Platform::Platform() {
  this->width = 125.0f;
  this->height = 15.0f;
  this->pos = {(float) (GetScreenWidth() - width) / 2, (float) (GetScreenHeight() - 20)};
  this->speed = 5;
  this->rect = {pos.x, pos.y, width, height};
}

void Platform::draw() 
{ 
  DrawRectangleRounded(rect, 2, 50, WHITE);
}

Rectangle Platform::getRect()
{
  return rect;
}

void Platform::update() { move(); }

void Platform::move() {
  if (IsKeyDown(KEY_RIGHT)) pos.x += speed;
  if (IsKeyDown(KEY_LEFT)) pos.x -= speed;

  pos.x = Clamp(pos.x, 0.0f, GetScreenWidth() - width);
  rect.x = pos.x;
  rect.y = pos.y;
}