#include "ball.h"

Ball::Ball()
{
    this->rad = 10;
    this->xSpeed = 4.0f;
    this->ySpeed = 4.0f;
    this->pos = {(float) (GetScreenWidth() / 2), 580};
}

void Ball::draw()
{
    DrawCircle(pos.x, pos.y, rad, WHITE);
}

void Ball::update()
{
    move();
}

void Ball::move()
{
    pos.y -= ySpeed;
    pos.x += xSpeed;

    if (pos.x > GetScreenWidth() - rad || pos.x < rad)
    {
        xSpeed *= -1;
    }

    if (pos.y < rad)
    {
        ySpeed *= -1;
    }
}