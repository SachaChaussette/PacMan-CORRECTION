#include "Food.h"
#include "PacMan.h"
#include "Game.h"

Food::Food(Level* _level, const string& _path, const Vector2f& _shapeSize, const int _points, const EntityType& _type)
	: Entity(_level, _path, _shapeSize, _type)
{
	points = _points;
	collider->AddCallback(ET_PACMAN, [&](Entity* _entity) { Death(_entity); });
}

void Food::Death(Entity* _entity)
{
	Destroy();
}

void Food::Destroy()
{
	if (type = ET_EATABLE)
	{
		level->RemoveEatable(this);
	}
	else if (type = ET_APPLE)
	{
		level->ActiveVulnerableEvent();
		level->RemoveEntity(this);
	}
	__super::Destroy();
	
}

