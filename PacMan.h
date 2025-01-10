#pragma once

#include "CoreMinimal.h"
#include "Entity.h"
#include "PlayerMovementComponent.h"
#include "LifeComponent.h"
#include "AnimationComponent.h"

class PacMan : public Entity
{
	PlayerMovementComponent* movement;
	LifeComponent* life;
	AnimationComponent* animation;

public :
	inline PlayerMovementComponent* GetMovementComponent()
	{
		return movement;
	}
	inline AnimationComponent* GetAnimationComponent()
	{
		return animation;
	}
	inline LifeComponent* GetLifeComponent()
	{
		return life;
	}

public:
	PacMan(Level* _level, const Vector2f& _shapeSize);
	~PacMan();

private: 
	void SetupInputs();
	void EatGhost(Entity* _entity);
	void EatEatable(Entity* _entity);
	void EatApple(Entity* _entity);
	void RetrieveScore(Food* _food);
public:
	virtual void Update() override;
	void Death();
};

