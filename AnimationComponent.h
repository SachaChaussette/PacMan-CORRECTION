#pragma once

#include "Component.h"

class AnimationComponent : public Component
{
	bool canRun;
	bool isLoop;
	float speed;
	Vector2i spriteSize;
	Vector2i grid;
	Vector2i currentFrame;
	RectangleShape* shape;

public:
	inline void SetCurrentRow(const int _rowIndex)
	{
		currentFrame.y = _rowIndex;
	}
	inline void SetRunStatus(const bool _status)
	{
		canRun = _status;
	}
	inline void ToggleRunStatus()
	{
		canRun = !canRun;
	}
public:
	AnimationComponent(Entity* _owner, const Vector2i& _spriteSize, const Vector2i& _grid,
		const float& _speed, const bool _isLoop = true);

private:
	void ChangeNextFrame();
	IntRect ComputeFrameRect();
	void Reset();
public:
	virtual void Update() override;
	void SetCurrentFrame(const Vector2i& _frame);
};

