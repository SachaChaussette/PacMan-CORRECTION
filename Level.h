#pragma once

#include "CoreMinimal.h"
#include "Entity.h"

class Level
{
	string name;
	string prefixPath;
	vector<Entity*> entities;
	Vector2u mapSize;

public:
	inline Vector2u GetMapSize() const
	{
		return mapSize;
	}
public:
	Level(const string& _name);
	~Level();


private:
	void Generate();
	void PlaceEntity(const Vector2i& _coords, const Vector2f& _shapeSize, Entity* _entity);
	void SpawnEntity(const char _symbol, const Vector2f& _shapeSize, const Vector2i& _coords);
public:
	void Display(RenderWindow& _window) const;
};

