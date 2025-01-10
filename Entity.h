#pragma once

#include "Object.h"
#include "Level.h"
#include "EntityType.h"

enum ColliderType;
class ColliderComponent;

class Level;



class Entity : public Object
{
	Vector2f shapeSize;
	bool isToRemove;

protected:
	EntityType type;
	ColliderComponent* collider;
	Texture texture;
	u_int spriteIndex;
	RectangleShape* shape;
	Level* level;

public:
	inline void AddToRemove()
	{
		isToRemove = true;
	}
	inline bool GetIsToRemove() const
	{
		return isToRemove;
	}
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
	inline EntityType GetType() const
	{
		return type;
	}
public:
	Entity(Level* _level, const string& _name, const Vector2f& _shapeSize, 
		const EntityType& _type, const bool _isBlocking = false);
	~Entity();
public:
	virtual void Update() override;
	virtual void Destroy();
};

