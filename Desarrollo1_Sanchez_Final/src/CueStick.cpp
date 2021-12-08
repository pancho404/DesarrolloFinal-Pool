#include "CueStick.h"

CueStick::CueStick(Vector2 position, bool available) {
    this->position = position;
    this->available = available;
}

CueStick::~CueStick() {
}

float CueStick::GetRotation() {
    return 0.0f;
}

void CueStick::SetRotation(float rotation) {
}

Vector2 CueStick::GetPosition() {
    return Vector2();
}

void CueStick::SetPosition(Vector2 position) {
}

bool CueStick::GetAvailable() {
    return false;
}

void CueStick::SetAvailable(bool available) {
}
