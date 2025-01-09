#pragma once

#include "CoreMinimal.h"
#include "Entity.h"
#include "ColliderComponent.h"

enum FoodType
{
	FT_EATABLE,
	FT_APPLE,
	FT_GHOST,

	FT_COUNT,
};

class Food : public Entity
{
	int points;
	FoodType type;

public:
	Food(Level* _level, const string& _path, const Vector2f& _shapeSize, const int _points, const FoodType& _type);

protected:
	virtual bool Eat(Entity* _entity);
};

