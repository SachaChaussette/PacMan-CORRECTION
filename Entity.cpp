#include "Entity.h"
#include "TextureManager.h"
#include "ColliderComponent.h"

Entity::Entity(Level* _level, const string& _name, const Vector2f& _shapeSize, 
	const ColliderType& _colliderType, const function<void(Entity* _entity)>& _callback)
{
	level = _level;
	shapeSize = _shapeSize;
	shape = new RectangleShape(_shapeSize);
	shape->setOrigin(Vector2f(_shapeSize.x / 2,_shapeSize.y / 2));
	TextureManager::GetInstance().InitShape(*shape, texture, _name);

	tileIndex = 0;

	collider = new ColliderComponent(_callback, _colliderType, this);
}

Entity::~Entity()
{
	delete shape;
	delete collider;
}

void Entity::Update()
{
	collider->Update();
}

void Entity::AddPoints(const int _points)
{
	level->AddScore(_points);
}

void Entity::UpdateTileIndex(const u_int& _maxTile, const u_int& _timeToWait)
{
    static u_int _time = 0;

    if (++_time % _timeToWait == 0)
    {
        ++tileIndex %= _maxTile;
        UpdateShape();
    }
    
}
void Entity::UpdateShape() const
{
    shape->setTextureRect(IntRect(Vector2i(15 * tileIndex, 0), Vector2i(15, 15)));
}

