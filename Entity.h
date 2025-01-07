#pragma once

#include "CoreMinimal.h"

class Entity
{
	Vector2f shapeSize;
	RectangleShape shape;
	Texture texture;
	Vector2i coords;

public:
	inline void SetPosition(const Vector2i& _coords)
	{
		const float _x = _coords.x;
		const float _y = _coords.y;
		shape.setPosition(Vector2f(_x,_y));
	}
	inline Vector2f GetShapeSize() const
	{
		return shapeSize;
	}
	inline RectangleShape GetShape() const
	{
		return shape;
	}

public:
	Entity(const string& _name, const Vector2f& _shapeSize);

private:
};

