#pragma once

#include "CoreMinimal.h"
#include "Component.h"
#include "Entity.h"

class LifeComponent : public Component
{
	int lifesCount;

public:
	LifeComponent(Entity* _owner);


public:
	void RemoveLife();
	void ResetLife();
};
