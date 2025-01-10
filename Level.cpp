#include "Level.h"
#include "FileLoader.h"
#include "PacMan.h"
#include "ColliderComponent.h"
#include "Food.h"
#include "Ghost.h"
#include "Game.h"

Level::Level(const string& _name, RenderWindow& _window)
{
    name = _name;
    prefixPath = "Assets/Maps/";
    window = &_window;
    vulnerableTimer = new Timer(10, [&]() { DeactiveVulnerableEvent(); });
    Generate();
}

Level::~Level()
{
    delete vulnerableTimer;
    while (!entities.empty())
    {
        entities.pop_back();
    }
}

void Level::Generate()
{
    try
    {
        int _rowIndex = 0, _colIndex = 0, _currentIndex = 0;
        const Vector2f& _shapeSize = Vector2f(20.0f, 20.0f);
       
        const string& _data = FileLoader::GetInstance().ReadAll(prefixPath + name);
        const size_t& _dataCount = _data.size();

        for (; _currentIndex < _dataCount; _currentIndex++)
        {
            const char _symbol = _data[_currentIndex];
            if (_symbol == '\n')
            {
                _colIndex = 0;
                _rowIndex++;
                continue;
            }
            
            SpawnEntity(_symbol, _shapeSize, Vector2i(_colIndex, _rowIndex));
            _colIndex++;
        }
        mapSize = Vector2u(static_cast<unsigned>((_currentIndex / _rowIndex - 1) * _shapeSize.x),
                           static_cast<unsigned>(_rowIndex * _shapeSize.y));
    }
    catch (const exception& _error)
    {
        cerr << _error.what() << endl;
    }
}

Vector2f Level::ComputePosition(const Vector2i& _coords, const Vector2f& _shapeSize)
{
    const float _x = _coords.x * _shapeSize.x;
    const float _y = _coords.y * _shapeSize.y;
    return Vector2f(_x, _y) + _shapeSize / 2.0f;
}

void Level::SpawnEntity(const char _symbol, const Vector2f& _shapeSize, const Vector2i& _coords)
{
    const Vector2f& _position = ComputePosition(_coords, _shapeSize);

    map<char, function<Entity*()>> _textureDataBase =
    {
        {'#', [&]()
            {
                return new Entity(this, "Walls/Wall", _shapeSize, CT_BLOCK);
            }
        },
        {'.', [&]()
            {
                Food* _eatable = new Food(this, "Foods/Point", _shapeSize, 10,FT_EATABLE);
                eatables.insert(_eatable);
                return _eatable;
            }
        },
        {'*', [&]()
            {
                return new Food(this, "Foods/Apple", _shapeSize, 700, FT_APPLE);
            }
        },
        {'C', [&]()
            {
                playerStart = _position;
                pacMan = new PacMan(this, _shapeSize);
                return pacMan;
            }
        },
        {'G', [&]()
            {
                Ghost* _ghost = new Ghost(this, _shapeSize);
                ghosts.insert(_ghost);
                return _ghost;
            }
        },
    };
    
    Entity* _entity = _textureDataBase[_symbol]();
    _entity->SetPosition(_position);
    entities.push_back(_entity);
}

void Level::Display() const
{
    for (const Entity* _entity : entities)
    {
        window->draw(*_entity->GetShape());
    }
}

void Level::DeactiveVulnerableEvent()
{
    for (Ghost* _ghost : ghosts)
    {
        _ghost->SetVulnerableStatus(false);
    }
}

void Level::Update()
{
    vulnerableTimer->Update(0.5f);
    for (Entity* _entity : entities)
    {
        _entity->Update();
    }
    Display();
}

#include <set>
Entity* Level::CheckCollider(const Vector2f& _tagetPosition)
{
    for (Entity* _entity : entities)
    {
        if (_entity->GetPosition() == _tagetPosition) return _entity;
    }
    return nullptr;
}

Entity* Level::GetEntityByPosition(const Vector2f& _pos)
{
    for (Entity* _entity : entities)
    {
        if (_entity->GetPosition() == _pos) 
        {
            return _entity;
        }
    }
    return nullptr;
}

void Level::RemoveEatable(Food* _eatable)
{
    eatables.erase(eatables.find(_eatable));
    if (IsOver())
    {
        Game::GetInstance().Stop();
    }
}

void Level::ActiveVulnerableEvent()
{
    for (Ghost* _ghost : ghosts)
    {
        _ghost->SetVulnerableStatus(true);
    }

    vulnerableTimer->Start();
}

void Level::Respawn(Entity* _entity)
{
    _entity->SetPosition(playerStart);
}
