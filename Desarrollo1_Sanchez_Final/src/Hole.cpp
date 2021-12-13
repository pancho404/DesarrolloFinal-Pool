#include "Hole.h"

Hole::Hole(Vector2 position, int radius)
{
    this->position.x = position.x;
    this->position.y = position.y;
    this->radius = radius;
}

Hole::~Hole()
{

}

Vector2 Hole::GetPosition()
{
    return position;
}

void Hole::SetPosition(Vector2 position)
{
    this->position.x = position.x;
    this->position.y = position.y;
}

int Hole::GetRadius()
{
    return radius;
}

void Hole::Draw()
{
    DrawCircle(position.x, position.y, radius, BLACK);
}
