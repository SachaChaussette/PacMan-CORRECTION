#include "Game.h"
#include "InputManager.h"

void Game::LoadLevel(const string& _path)
{
    level = new Level(_path, *window);
}

void Game::SetWindow(const Vector2u& _levelSize, const Vector2u& _tileSize, const string& title)
{
    window = new RenderWindow(VideoMode(Vector2u(_levelSize.x * _tileSize.x, _levelSize.y * _tileSize.y)), title);
}

void Game::Loop()
{
    while (window->isOpen())
    {
        InputManager::GetInstance().ConsumeInputs(*window);

        window->clear();
        level->Update();
        window->display();
        SLEEP(500ms);
    }
}
