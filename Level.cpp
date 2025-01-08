#include "Level.h"
#include "FileLoader.h"
#include "PacMan.h"

Level::Level(const string& _name)
{
    name = _name;
    prefixPath = "Assets/Maps/";
    Generate();

}

Level::~Level()
{
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
    _entity->SetPosition(Vector2i(_x, _y));
}

void Level::SpawnEntity(const char _symbol, const Vector2f& _shapeSize, const Vector2i& _coords)
{
    map<char, function<Entity*()>> _textureDataBase =
    {
        {'#', [&]()
            {
                return new Entity("Walls/Wall", _shapeSize);
            }
        },
        {'.', [&]()
            {
                return new Entity("Foods/Point", _shapeSize);
            }
        },
        {'*', [&]()
            {
                return new Entity("Foods/Apple", _shapeSize);
            }
        },
        {'C', [&]()
            {
                return new PacMan("PacMan/Moving/PacMan_Eating_1", _shapeSize);
            }
        },
        {'G', [&]()
            {
                return new Entity("Ghosts/Blue/BlueGhost_Vulnerable", _shapeSize);
            }
        },
    };

    Entity* _entity = _textureDataBase[_symbol]();
    PlaceEntity(_coords, _shapeSize, _entity);
    entities.push_back(_entity);
}


void Level::Display(RenderWindow& _window) const
{
    for (const Entity* _entity : entities)
    {
        _window.draw(*_entity->GetShape());
    }
}
