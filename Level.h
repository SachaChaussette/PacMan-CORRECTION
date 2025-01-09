#pragma once

#include "CoreMinimal.h"

class Entity;
class PacMan;
class Ghost;
class Food;

struct Timer
{
	bool isRunning;
	bool isLoop;
	float duration;
	float currentTime;
	function<void()> callback;

	Timer(const float _duration, const function<void()>& _callback, const bool _isLoop = false)
	{
		callback = _callback;
		isRunning = false;
		currentTime = 0.0f;
		duration = _duration;
		isLoop = _isLoop;
	}

	void Start()
	{
		Reset();
		isRunning = true;
	}

	void Update(const float _deltaTime)
	{
		if (!isRunning) return;
		currentTime += _deltaTime;
		if (currentTime >= duration)
		{
			callback();
			
			isRunning = isLoop;

			Reset();
		}
	}
	void Reset()
	{
		currentTime = 0.0f;
	}
};

class Level
{
	string name;
	string prefixPath;
	vector<Entity*> entities;
	set<Food*> eatables;
	set<Ghost*> ghosts;
	Vector2u mapSize;
	Vector2f playerStart;
	RenderWindow* window;
	Timer* vulnerableTimer;
	int points;

	Entity* pacMan;

public:
	inline bool IsOver() const
	{
		return eatables.size() <= 0;
	}
	inline Vector2u GetMapSize() const
	{
		return mapSize;
	}
	inline Entity* GetPacMan() const
	{
		return pacMan;
	}
public:
	Level() = default;
	Level(const string& _name, RenderWindow& _window);
	~Level();


private:
	void Generate();
	Vector2f ComputePosition(const Vector2i& _coords, const Vector2f& _shapeSize);
	void SpawnEntity(const char _symbol, const Vector2f& _shapeSize, const Vector2i& _coords);
	void Display() const;
	void DeactiveVulnerableEvent();
public:
	void Update();
	Entity* CheckCollider(const Vector2f& _tagetPosition);
	Entity* GetEntityByPosition(const Vector2f& _pos);
	void RemoveEatable(Food* _eatable);
	void ActiveVulnerableEvent();
	void Respawn(Entity* _entity);
};

