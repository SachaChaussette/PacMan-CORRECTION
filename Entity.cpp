#include "Entity.h"
#include "TextureManager.h"
#include "ColliderComponent.h"

Entity::Entity(Level* _level, const string& _name, const Vector2f& _shapeSize, 
	 const EntityType& _type, const bool _isBlocking)
{
	isToRemove = false;
	level = _level;
	shapeSize = _shapeSize;
	shape = new RectangleShape(_shapeSize);
	shape->setOrigin(Vector2f(_shapeSize.x / 2,_shapeSize.y / 2));
	TextureManager::GetInstance().InitShape(*shape, texture, _name);
	spriteIndex = 0;

	collider = new ColliderComponent(this, _isBlocking);
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

void Entity::Destroy()
{
	level->RemoveEntity(this);
	delete this;
}
