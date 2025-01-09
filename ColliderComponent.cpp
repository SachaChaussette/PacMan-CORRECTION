#include "ColliderComponent.h"

ColliderComponent::ColliderComponent(const function<bool(Entity* _entity)>& _callback, const ColliderType& _type, Entity* _owner) : Component(_owner)
{
	type = _type;
	callback = _callback;
}

bool ColliderComponent::Collide(Entity* _entity)
{
	if (type == CT_OVERLAP)
	{
		return callback(_entity);
	}
	return type != CT_BLOCK;
}
