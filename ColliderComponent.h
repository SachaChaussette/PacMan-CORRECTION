#pragma once

#include "Component.h"

enum ColliderType
{
	CT_NONE,
	CT_OVERLAP,
	CT_BLOCK,
};

class ColliderComponent : public Component
{
	ColliderType type;
	function<void(Entity* _entity)> callback;

public:
	inline ColliderType GetType()
	{
		return type;
	}
public:
	ColliderComponent(const function<void(Entity* _entity)>& _callback, const ColliderType& _type, Entity* _owner);

public:
	bool Collide(Entity* _entity);
};

