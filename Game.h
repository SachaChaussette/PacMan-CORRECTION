#pragma once

#include "Level.h"
#include "Singleton.h"

class Game : public Singleton<Game>
{
	Level* level;
	RenderWindow* window;
	string title;

public:
	void LoadLevel(const string& _path);
	void SetWindow(const Vector2u& _levelSize, const Vector2u& _tileSize, const string& title);
	void Loop();
};

