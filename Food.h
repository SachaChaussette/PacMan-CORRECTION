#pragma once

#include "CoreMinimal.h"
#include "Entity.h"
#include "ColliderComponent.h"


class Food : public Entity
{
	int points;

public:
	inline int GetPoints() const
	{
		return points;
	}
public:
	Food(Level* _level, const string& _path, const Vector2f& _shapeSize, 
		const int _points, const EntityType& _type);
private:
	void Death(Entity* _entity);
protected:
	virtual void Destroy() override;
};

