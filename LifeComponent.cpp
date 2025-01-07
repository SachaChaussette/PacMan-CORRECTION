#include "LifeComponent.h"

LifeComponent::LifeComponent(Entity* _owner) : Component(_owner)
{
	ResetLife();
}

void LifeComponent::RemoveLife()
{
	lifesCount--;
	lifesCount %= 3;
}

void LifeComponent::ResetLife()
{
	lifesCount = 3;
}
