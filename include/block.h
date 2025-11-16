#include "raylib.h"

class Block {
public:
    Block();
    Block(float posX, float posY, Color color);
    Rectangle getRect();
    void draw();
    bool active;

private:
    Vector2 pos;
    Color color;
    Rectangle rect;
    float height;
    float width;
};