#include "Food.h"
#include "PacMan.h"
#include "Game.h"

Food::Food(Level* _level, const string& _path, const Vector2f& _shapeSize, const int _points
	, const FoodType& _type) : Entity(_level, _path, _shapeSize, CT_OVERLAP, [&](Entity* _entity) { Eat(_entity); })
{
	type = _type;
	points = _points;
}

bool Food::Eat(Entity* _entity)
{
	if (PacMan* _pacMan = dynamic_cast<PacMan*>(_entity))
	{
		if(type == FT_EATABLE)
		{
			level->RemoveEatable(this);
		}

		else if(type == FT_APPLE)
		{
			level->ActiveVulnerableEvent();
		}

		type = FT_COUNT;
		shape->setScale(Vector2f());
		collider->SetType(CT_NONE);
		Game::GetInstance().AddScore(points);
	}
	return true;
}

