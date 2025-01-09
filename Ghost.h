#pragma once

#include "Food.h"
#include "GhostMovementComponent.h"
#include "AnimationComponent.h"

enum GhostStates
{
	GS_ANGRY,
	GS_EATABLE,

	GS_COUNT,
};

class Ghost : public Food
{
	bool isVulnerable;
	int damages;
	GhostMovementComponent* movement;
	AnimationComponent* animation;

public:
	inline void SetVulnerableStatus(const bool _status)
	{
		isVulnerable = _status;
	}

public:
	Ghost(Level* _level, const Vector2f& _shapeSize);
	~Ghost();
public:
	virtual void Update() override;
	virtual bool Eat(Entity* _entity) override;
	void SetupInputs();
};

