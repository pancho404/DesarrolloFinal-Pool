#include "Ball.h"

Ball::Ball(Vector2 position, Color color, TypeOfBall type, int id)
{
    this->position = position;
    this->color = color;
    this->type = type;
    this->id = id;
    acceleration = { 0 };
    velocity = { 0 };
    direction = { 0 };
    onGame = true;
    isMoving = false;
}

Ball::~Ball() 
{

}

Vector2 Ball::GetPosition()
{
    return position;
}

void Ball::SetPosition(Vector2 position)
{
    this->position.x = position.x;
    this->position.y = position.y;
}

Vector2 Ball::GetVelocity() 
{
    return velocity;
}

void Ball::SetVelocity(Vector2 velocity)
{
    this->velocity.x = velocity.x;
    this->velocity.y = velocity.y;
}

Vector2 Ball::GetDirection() 
{
    return direction;
}

void Ball::SetDirection(Vector2 direction)
{
    this->direction.x = direction.x;
    this->direction.y = direction.y;
}

Color Ball::GetColor()
{
    return color;
}

bool Ball::GetOnGame()
{
    return onGame;
}

void Ball::SetOnGame(bool onGame)
{
    this->onGame = onGame;
}

bool Ball::GetIsMoving()
{
    return isMoving;
}

void Ball::SetIsMoving(bool isMoving) 
{
    this->isMoving = isMoving;
}

void Ball::Draw() 
{
    DrawCircle(position.x, position.y, radius, color);
}


void Ball::Hit(Vector2 mousePosition)
{

    Vector2 forceOfHit = { (position.x - mousePosition.x) * 2,(position.y - mousePosition.y) * 2 }; //La fuerza es el doble de la diferencia entre la posición del mouse y la pelota

    SetVelocity(forceOfHit);
}



TypeOfBall Ball::GetType()
{
    return type;
}

Vector2 Ball::GetAcceleration()
{
    return acceleration;
}

void Ball::SetAcceleration(Vector2 acceleration)
{
    this->acceleration = acceleration;
}

void Ball::Move(Vector2 movement)
{
    position.x += movement.x;
    position.y += movement.y;
}

int Ball::GetID()
{
    return id;
}
