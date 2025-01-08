#pragma once

#include "CoreMinimal.h"
#include "Entity.h"
#include "MovementComponent.h"
#include "LifeComponent.h"

class PacMan : public Entity
{
	MovementComponent* movement;
	LifeComponent* life;

public:
	PacMan(const string& _path, const Vector2f& _shapeSize);
	~PacMan();

private: 
	void SetupInputs();
};

