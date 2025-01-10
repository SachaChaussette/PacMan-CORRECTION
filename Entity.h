#pragma once

#include "Object.h"
#include "Level.h"

enum ColliderType;
class ColliderComponent;

class Level;

class Entity : public Object
{
	Vector2f shapeSize;


protected:
	ColliderComponent* collider;
	Texture texture;
	u_int spriteIndex;
	RectangleShape* shape;
	Level* level;

public:
	inline Level* GetLevel() const
	{
		return level;
	}
	inline void SetPosition(const Vector2f& _coords)
	{
		const float _x = _coords.x;
		const float _y = _coords.y;
		shape->setPosition(Vector2f(_x,_y));
	}
	inline Vector2f GetShapeSize() const
	{
		return shapeSize;
	}
	inline RectangleShape* GetShape() const
	{
		return shape;
	}
	inline Vector2f GetPosition() const
	{
		return shape->getPosition();
	}
	inline ColliderComponent* GetCollider() const
	{
		return collider;
	}
public:
	Entity(Level* _level, const string& _name, const Vector2f& _shapeSize, 
			const ColliderType& _colliderType, const function<void(Entity* _entity)>& _callback = {});
	~Entity();
public:
	virtual void Update() override;
};

