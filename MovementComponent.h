#pragma once

#include "CoreMinimal.h"
#include "Component.h"

class MovementComponent : public Component
{
protected:
	bool canMove;
	int speed;
	Vector2i direction;

public:
	inline void ToggleMoveStatus()
	{
		canMove = !canMove;
	}
	inline void SetDirection(const Vector2i& _newDirection)
	{
		if (!canMove) return;

		direction = _newDirection;
	}
public:
	MovementComponent(Entity* _owner);

protected:
	void Move();
public:
	virtual void Update() override;
};

