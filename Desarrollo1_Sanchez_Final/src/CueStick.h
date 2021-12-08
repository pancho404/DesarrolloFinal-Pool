#pragma once
#include "raylib.h"

class CueStick {
private:
	float rotation;
	Vector2 position;
	bool available;
public:
	CueStick(Vector2 position, bool available);
	~CueStick();
	float GetRotation();
	void SetRotation(float rotation);
	Vector2 GetPosition();
	void SetPosition(Vector2 position);
	bool GetAvailable();
	void SetAvailable(bool available);
};

