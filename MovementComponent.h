#pragma once

#include "CoreMinimal.h"
#include "Component.h"

class MovementComponent : public Component
{
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

		if (_newDirection != direction)
		{
			Rotate(_newDirection);
		}
		direction = _newDirection;
	}
public:
	MovementComponent(Entity* _owner);

private:
	void Move();
	void Rotate(const Vector2i& _direction);

public:
	virtual void Update() override;
};

