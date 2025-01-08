#include "Food.h"
#include "PacMan.h"

Food::Food(Level* _level, const string& _path, const Vector2f& _shapeSize, const int _points
	, const FoodType& _type) : Entity(_level, _path, _shapeSize, CT_OVERLAP, [&](Entity* _entity) {Eat(_entity); })
{
	type = _type;
	points = _points;
}

void Food::Eat(Entity* _entity)
{
	if (PacMan* _pacMan = dynamic_cast<PacMan*>(_entity))
	{
		_pacMan->AddPoints(points);
		shape->setScale(Vector2f());
		type = FT_COUNT;
	}
}

