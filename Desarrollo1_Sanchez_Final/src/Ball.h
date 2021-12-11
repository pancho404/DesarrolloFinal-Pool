#pragma once

#include "raylib.h"
#include <cmath>

enum class TypeOfBall {
	WHITEBALL,
	BLACKBALL,
	STRIPED,
	SMOOTH
};

static float tableFriction = 0.2f;
static float gravity = 9.8f;
static float airDensity = 1.225f;
static float constantAirFriction = 0.000000667f;
static int radius = 16;
static float mass = 156;
static float friction = tableFriction * (mass * gravity);
static float airFriction = constantAirFriction * 0.5f * airDensity * (radius * radius) / 4;

class Ball {
private:
	float acceleration;
	Vector2 position;
	Vector2 direction;
	Vector2 velocity;
	Color color;
	bool onGame;
	bool isMoving;
	TypeOfBall type;
public:
	Ball(Vector2 position, Color color, TypeOfBall type);
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
	void Movement();
	void Hit(Vector2 mousePosition);
	TypeOfBall GetType();
	void SetAcceleration(float acceleration);
	float GetForce();
	void SetForce(Vector2 force);
	void Move(Vector2 movement);
};

