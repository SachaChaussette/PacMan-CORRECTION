#include "PlayerMovementComponent.h"
#include "Entity.h"
#include "ColliderComponent.h"

PlayerMovementComponent::PlayerMovementComponent(Entity* _owner) : MovementComponent(_owner)
{
}

void PlayerMovementComponent::Move()
{
	if (!canMove) return;

	RectangleShape& _shape = *owner->GetShape();

	const float _x = direction.x * speed * _shape.getSize().x;
	const float _y = direction.y * speed * _shape.getSize().y;

	const Vector2f& _destination = _shape.getPosition() + Vector2f(_x, _y);
	Entity* _entity = owner->GetLevel()->CheckCollider(_destination);
	const bool _isGhost = dynamic_cast<Ghost>(_entity);

	if (!_entity || _entity->GetCollider()->Collide(owner) && !_isGhost)
	{
		_shape.setPosition(_destination);
	}

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
	Move();
}
