#pragma once

#include "CoreMinimal.h"

class Entity;

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

public:
	virtual void Update();
};

