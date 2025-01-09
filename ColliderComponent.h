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
	function<bool(Entity* _entity)> callback;

public:
	inline void SetType(const ColliderType& _type)
	{
		type = _type;
	}
	inline ColliderType GetType()
	{
		return type;
	}
public:
	ColliderComponent(const function<bool(Entity* _entity)>& _callback, const ColliderType& _type, Entity* _owner);

public:
	bool Collide(Entity* _entity);
};

