#include "block.h"

Block::Block()
{
    this->pos = { 0, 0 };
    this->color = WHITE;
    this->width = 86.0f;
    this->height = 30.0f;
    this->rect = {pos.x, pos.y, width, height};
    this->active = true;
}

Block::Block(float posX, float posY, Color color)
{
    this->pos = { posX, posY };
    this->color = color;
    this->width = 86.0f;
    this->height = 30.0f;
    this->rect = {pos.x, pos.y, width, height};
    this->active = true;
}

Rectangle Block::getRect()
{
    return rect;
}

void Block::draw()
{
    DrawRectangleRounded(rect, 0.2, 1, color);
}