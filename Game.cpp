#include "Game.h"
#include "InputManager.h"

Game::Game()
{
    score = 0;
    title = "Unknown";
}

Game::~Game()
{
    delete level;
    delete window;
}

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
        SLEEP(250ms);
    }
}

void Game::Stop()
{
    window->close();
}

void Game::Launch()
{
    SetWindow(Vector2u(MAP_SIZE_X, MAP_SIZE_Y), Vector2u(TILE_SIZE_X, TILE_SIZE_Y), "Pac Man");

    LoadLevel("SmallMap");

    Loop();
}
