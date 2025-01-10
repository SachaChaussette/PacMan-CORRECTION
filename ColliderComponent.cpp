#include "ColliderComponent.h"
#include "Entity.h"

ColliderComponent::ColliderComponent(Entity* _owner, const bool _isBlocking) : Component(_owner)
{
	isBlocking = _isBlocking;
	callbacks = map<EntityType, function<void(Entity* _entity)>>();
}

void ColliderComponent::Collide(Entity* _entity)
{
	const EntityType& _type = _entity->GetType();
	if(callbacks.contains(_type) && callbacks[_type])
	{
		callbacks[_type](_entity);
	}
}

void ColliderComponent::AddCallback(const EntityType& _type, const function<void(Entity* _entity)>& _callback)
{
	callbacks.insert(make_pair(_type, _callback));
}
