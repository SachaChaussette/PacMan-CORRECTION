#pragma once

#include "CoreMinimal.h"
#include "Entity.h"

class Component
{
protected:
	Entity* owner;

public:
	inline Entity* GetOwner() const
	{
		return owner;
	}

public:
	Component(Entity* _owner);
};

