#pragma once

#include "CoreMinimal.h"

class Entity;
class PacMan;

class Level
{
	string name;
	string prefixPath;
	vector<Entity*> entities;
	Vector2u mapSize;
	RenderWindow* window;
	int points;

	PacMan* pacMan;


public:
	inline Vector2u GetMapSize() const
	{
		return mapSize;
	}
public:
	Level() = default;
	Level(const string& _name, RenderWindow& _window);
	~Level();


private:
	void Generate();
	void PlaceEntity(const Vector2i& _coords, const Vector2f& _shapeSize, Entity* _entity);
	void SpawnEntity(const char _symbol, const Vector2f& _shapeSize, const Vector2i& _coords);
	void Display() const;
public:
	void Update();
	void AddScore(const int _points);
	Entity* CheckCollider(const Vector2f& _tagetPosition);
};

