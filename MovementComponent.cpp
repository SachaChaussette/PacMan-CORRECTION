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

}
