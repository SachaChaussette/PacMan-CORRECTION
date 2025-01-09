#include "LifeComponent.h"
#include "Game.h"

LifeComponent::LifeComponent(Entity* _owner) : Component(_owner)
{
	ResetLife();
}

void LifeComponent::RemoveLife()
{
	lifesCount--;

	if (lifesCount <= 0)
	{
		Game::GetInstance().Stop();
	}
}

void LifeComponent::ResetLife()
{
	lifesCount = 3;
}
