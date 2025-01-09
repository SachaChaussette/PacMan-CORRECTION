#pragma once

#include "MovementComponent.h"

class GhostMovementComponent : public MovementComponent
{
	queue<Vector2u> path;
	Vector2u targetPos;
public:
	GhostMovementComponent(Entity* _owner);
public:
	bool RetrieveNextPos();
	bool TryGetNextPos();
	void SetTargetPosition(const Vector2u& _targetPos);
	void MoveToTarget();

public:
	virtual void Update() override;
};

