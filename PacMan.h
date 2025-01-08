#pragma once

#include "CoreMinimal.h"
#include "Entity.h"
#include "MovementComponent.h"
#include "LifeComponent.h"

class PacMan : public Entity
{
	MovementComponent* movement;
	LifeComponent* life;

public :
	inline MovementComponent* GetMovementComponent()
	{
		return movement;
	}

public:
	PacMan(Level* _level, const Vector2f& _shapeSize);
	~PacMan();

private: 
	void SetupInputs();
public:
	virtual void Update() override;
};

