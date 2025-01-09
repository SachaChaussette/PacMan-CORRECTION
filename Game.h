#pragma once

#include "Level.h"
#include "Singleton.h"

class Game : public Singleton<Game>
{
	Level* level;
	RenderWindow* window;
	string title;
	int score;

public:
	inline void AddScore(const int _score)
	{
		score += _score;
	}

public:
	Game();
	~Game();
private:
	void LoadLevel(const string& _path);
	void SetWindow(const Vector2u& _levelSize, const Vector2u& _tileSize, const string& title);
	void Loop();
public:
	void Launch();
	void Stop();
};

