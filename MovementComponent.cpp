#include "MovementComponent.h"
#include "ColliderComponent.h"
#include "Entity.h"
#include "PacMan.h"
#include "Level.h"

MovementComponent::MovementComponent(Entity* _owner) : Component(_owner)
{
	canMove = false;
	speed = 1;
	direction = Vector2i(1,0);

}

void MovementComponent::Update()
{
	Move();
}

void MovementComponent::Move()
{
	if (!canMove) return;

	RectangleShape& _shape = *owner->GetShape();

	const float _x = direction.x * speed * _shape.getSize().x;
	const float _y = direction.y * speed * _shape.getSize().y;

	const Vector2f& _destination = _shape.getPosition() + Vector2f(_x, _y);
	Entity* _entity = owner->GetLevel()->CheckCollider(_destination);

	if (!_entity || _entity->GetCollider()->Collide(owner))
	{
		_shape.setPosition(_destination);
	}
	
}

void MovementComponent::Rotate(const Vector2i& _direction)
{

	const float _angle = _direction.y != 0 ? 90.0f * _direction.y 
						: _direction.x < 0 ? 180.0f 
						: 0.0f;
	owner->GetShape()->setRotation(degrees(_angle));
}