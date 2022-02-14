#pragma once

#include "raylib.h"
#include <cmath>

enum class TypeOfBall 
{
	WHITEBALL,
	BLACKBALL,
	STRIPED,
	SMOOTH
};

const float tableFriction = 0.2f;
const float gravity = 9.8f;
const float airDensity = 1.225f;
const float constantAirFriction = 0.000000667f;
const int radius = 18;
const float mass = 156;
const float friction = tableFriction * (mass * gravity);
const float airFriction = constantAirFriction * 0.5f * airDensity * (radius * radius) / 4;

class Ball 
{
private:
	Texture2D texture;
	Vector2 acceleration;
	Vector2 position;
	Vector2 direction;
	Vector2 velocity;
	Color color;
	bool onGame;
	bool isMoving;
	TypeOfBall type;
	int id;
public:
	Ball(Vector2 position, Color color, TypeOfBall type, int id);
	~Ball();
	Vector2 GetPosition();
	void SetPosition(Vector2 position);
	Vector2 GetVelocity();
	void SetVelocity(Vector2 velocity);
	Vector2 GetDirection();
	void SetDirection(Vector2 direction);
	Color GetColor();
	bool GetOnGame();
	void SetOnGame(bool onGame);
	bool GetIsMoving();
	void SetIsMoving(bool isMoving);
	void Draw();
	TypeOfBall GetType();
	Vector2 GetAcceleration();
	void Hit(Vector2 mousePosition);
	void SetAcceleration(Vector2 acceleration);
	void Move(Vector2 movement);
	void SetTexture(Texture2D texture);
	int GetID();
};

