#pragma once

#include "MovementComponent.h"

class PlayerMovementComponent : public MovementComponent
{

public:
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
	PlayerMovementComponent(Entity* _owner);
private:
	void Move();
	void Rotate(const Vector2i& _direction);

public:
	virtual void Update() override;
};

