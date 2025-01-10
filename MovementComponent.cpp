#include "MovementComponent.h"
#include "ColliderComponent.h"
#include "Entity.h"
#include "PacMan.h"
#include "Level.h"
#include "Ghost.h"

MovementComponent::MovementComponent(Entity* _owner) : Component(_owner)
{
	canMove = false;
	speed = 1;
	direction = Vector2i(1,0);

}

void MovementComponent::Move()
{
	if (!canMove) return;

	RectangleShape& _shape = *owner->GetShape();

	const float _x = direction.x * speed * _shape.getSize().x;
	const float _y = direction.y * speed * _shape.getSize().y;

	const Vector2f& _destination = _shape.getPosition() + Vector2f(_x, _y);
	Entity* _entity = owner->GetLevel()->CheckCollider(_destination);

	if(_entity)
	{
		owner->GetCollider()->Collide(_entity);
		if(!_entity->GetIsToRemove())
		{
			_entity->GetCollider()->Collide(owner);
		}
	}

	if (!_entity || _entity->GetIsToRemove() || !_entity->GetCollider()->GetIsBlocking())
	{
		_shape.setPosition(_destination);
	}

}

void MovementComponent::Update()
{
	Move();
}
