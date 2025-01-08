#include "Entity.h"
#include "TextureManager.h"

Entity::Entity(const string& _name, const Vector2f& _shapeSize)
{
	shapeSize = _shapeSize;
	shape = new RectangleShape(_shapeSize);
	TextureManager::GetInstance().InitShape(*shape, texture, _name);
}

