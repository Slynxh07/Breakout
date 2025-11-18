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

void Ball::changeXDir()
{
    velocity.x *= -1;
}

void Ball::changeYDir()
{
    velocity.y *= -1;
}

void Ball::checkCollisionPlatform(Rectangle rect)
{
    if (CheckCollisionCircleRec(pos, rad, rect))
    {
        float hitPos = (pos.x - rect.x) / rect.width;

        velocity.x = (hitPos - 0.5f) * 8.0f;
        velocity.y *= -1;
    }
}

brickHit Ball::checkCollisionBlock(Rectangle rect)
{
    brickHit currHit = { false, 0, 0 };
    Vector2 prevPos = { pos.x - velocity.x, pos.y - velocity.y };
    if (CheckCollisionCircleRec(pos, rad, rect))
    {
        currHit.hit = true;

        float nearestX = fmaxf(rect.x, fminf(prevPos.x, rect.x + rect.width));
        float nearestY = fmaxf(rect.y, fminf(prevPos.y, rect.y + rect.height));

        currHit.overlapX = fabs(prevPos.x - nearestX);
        currHit.overlapY = fabs(prevPos.y - nearestY);

        /*
        bool fromLeft = prevPos.x + rad <= rect.x;
        bool fromRight = prevPos.x - rad >= rect.x + rect.width;
        
        if (fromLeft || fromRight) velocity.x *= -1;
        else velocity.y *= -1;
        return true;
        */
    }
    //return false;
    return currHit;
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

bool Ball::outOfBounds()
{
    if (pos.y > GetScreenHeight() + rad) return true;
    return false;
}