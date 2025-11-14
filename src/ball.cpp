#include "ball.h"

Ball::Ball()
{
    this->rad = 10;
    this->velocity = { 4, 4 };
    this->pos = {(float) (GetScreenWidth() / 2), (float) (GetScreenHeight() - 35)};
}

void Ball::draw()
{
    DrawCircle(pos.x, pos.y, rad, WHITE);
}

void Ball::update()
{
    move();
}

void Ball::checkCollision(Rectangle rect)
{
    if (CheckCollisionCircleRec(pos, rad, rect))
    {
        float hitPos = (pos.x - rect.x) / rect.width;

        velocity.x = (hitPos - 0.5f) * 8.0f;
        velocity.y *= -1;
    }
}

void Ball::move()
{
    pos.y -= velocity.y;
    pos.x += velocity.x;

    if (pos.x > GetScreenWidth() - rad || pos.x < rad)
    {
        velocity.x *= -1;
    }

    if (pos.y < rad)
    {
        velocity.y *= -1;
    }
}