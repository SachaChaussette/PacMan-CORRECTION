#pragma once

#include "MovementComponent.h"

class GhostMovementComponent : public MovementComponent
{
	queue<Vector2u> path;
	Vector2u targetPos;
	Vector2u nextPos;
	Vector2u currentPos;
public:
	GhostMovementComponent(Entity* _owner);
public:
	bool RetrieveNextPos();
	bool TryGetNextPos();
	void SetPath();
	void MoveToTarget();
	void ResetPath();
	void ComputeNewDirection();

public:
	virtual void Update() override;
};

