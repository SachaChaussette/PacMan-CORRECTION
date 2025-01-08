#include "Level.h"
#include "FileLoader.h"
#include "PacMan.h"
#include "ColliderComponent.h"
#include "Food.h"

Level::Level(const string& _name, RenderWindow& _window)
{
    name = _name;
    prefixPath = "Assets/Maps/";
    window = &_window;

    Generate();

}

Level::~Level()
{
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
       
        const string& _data = FileLoader::GetInstance().ReadAll(prefixPath + "SmallMap");
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

void Level::PlaceEntity(const Vector2i& _coords, const Vector2f& _shapeSize, Entity* _entity)
{
    const float _x = _coords.x * _shapeSize.x;
    const float _y = _coords.y * _shapeSize.y;
    _entity->SetPosition(Vector2f(_x, _y) + _shapeSize / 2.0f);
}

void Level::SpawnEntity(const char _symbol, const Vector2f& _shapeSize, const Vector2i& _coords)
{
    map<char, function<Entity*()>> _textureDataBase =
    {
        {'#', [&]()
            {
                return new Entity(this, "Walls/Wall", _shapeSize, CT_BLOCK);
            }
        },
        {'.', [&]()
            {
                return new Food(this, "Foods/Point", _shapeSize, 10,FT_EATABLE );
            }
        },
        {'*', [&]()
            {
                return new Food(this, "Foods/Apple", _shapeSize, 700, FT_APPLE);
            }
        },
        {'C', [&]()
            {
                pacMan = new PacMan(this,  _shapeSize);
                return pacMan;
            }
        },
        {'G', [&]()
            {
                return new Food(this, "Ghosts/Blue/BlueGhost_Vulnerable", _shapeSize, 1000, FT_GHOST);
            }
        },
    };
    
    Entity* _entity = _textureDataBase[_symbol]();

    PlaceEntity(_coords, _shapeSize, _entity);
    entities.push_back(_entity);
}

void Level::Display() const
{
    for (const Entity* _entity : entities)
    {
        window->draw(*_entity->GetShape());
    }
    window->draw(*pacMan->GetShape());
}

void Level::Update()
{
    for (Entity* _entity : entities)
    {
        _entity->Update();
    }
    Display();
}

void Level::AddScore(const int _points)
{
    points += _points;
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
