#include "ball.h"

Ball::Ball()
{
    this->rad = 10;
    this->speed = 4;
    this->pos = {(float) (GetScreenWidth() / 2), 580};
}

void Ball::draw()
{
    DrawCircle(pos.x, pos.y, rad, WHITE);
}

void Ball::update()
{
    //move();
}

void Ball::move()
{
    pos.y += speed;
    pos.x += speed;
}