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
	
public:
	MovementComponent(Entity* _owner);

protected:
	void Move();
public:
	virtual void Update() override;
};

