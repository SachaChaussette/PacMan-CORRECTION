#include "PlayerMovementComponent.h"
#include "Entity.h"
#include "ColliderComponent.h"
#include "Ghost.h"

PlayerMovementComponent::PlayerMovementComponent(Entity* _owner) : MovementComponent(_owner)
{
}



void PlayerMovementComponent::Rotate(const Vector2i& _direction)
{
	const float _angle = _direction.y != 0 ? 90.0f * _direction.y
		: _direction.x < 0 ? 180.0f
		: 0.0f;
	owner->GetShape()->setRotation(degrees(_angle));
}

void PlayerMovementComponent::Update()
{
	__super::Update();
}
