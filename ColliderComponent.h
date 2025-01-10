#pragma once

#include "Component.h"
#include "EntityType.h"

// TODO REMOVE
enum ColliderType
{
	CT_NONE,
	CT_OVERLAP,
	CT_BLOCK,

	CT_COUNT,
};

class ColliderComponent : public Component
{
	bool isBlocking;
	map<EntityType, function<void(Entity* _entity)>> callbacks;

public:

	inline bool GetIsBlocking()
	{
		return isBlocking;
	}
public:
	ColliderComponent(Entity* _owner, const bool _isBlocking = false);

public:
	void Collide(Entity* _entity);
	void AddCallback(const EntityType& _type, const function<void(Entity* _entity)>& _callback);
};

