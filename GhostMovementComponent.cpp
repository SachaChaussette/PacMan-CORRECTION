#include "GhostMovementComponent.h"
#include "AstarAlgo.h"
#include "Ghost.h"
#include "Macro.h"


GhostMovementComponent::GhostMovementComponent(Entity* _owner) : MovementComponent(_owner)
{
	path = queue<Vector2u>();
}

bool GhostMovementComponent::RetrieveNextPos()
{
	if (path.empty()) return false;

	currentPos = nextPos;

	nextPos = path.front();
	path.pop();

	return true;
}

bool GhostMovementComponent::TryGetNextPos()
{
	if (!path.empty())
	{
		if (!RetrieveNextPos()) return true;
	}
	return false;
}

void GhostMovementComponent::SetPath()
{
	AstarAlgo _astar = AstarAlgo(owner->GetLevel());

	vector<Vector2u> _collection = _astar.FindPath(Vector2u(owner->GetPosition()), targetPos);
	for (const Vector2u& _value : _collection)
	{
		path.push(_value);
	}
}

void GhostMovementComponent::MoveToTarget()
{
	if (!TryGetNextPos()) return;

	owner->SetPosition(Vector2f(nextPos));
	nextPos = Vector2u();
}

void GhostMovementComponent::ResetPath()
{
	while (!path.empty())
	{
		path.pop();
	}
}

void GhostMovementComponent::ComputeNewDirection()
{
	const vector<Vector2i>& _allDirections =
	{
		Vector2i(-1, 0),
		Vector2i(1, 0),
		Vector2i(0, -1),
		Vector2i(0, 1),
	};

	Vector2i _newDirection;
	do
	{
		_newDirection = GetRandomNumberInRange<Vector2i>(_allDirections);
	} while (_newDirection != direction /*&& _newDirection != direction * -1*/);
	direction = _newDirection;


	/*if (currentPos.x - nextPos.x < 0)
	{
		direction = Vector2i(1, 0);
	}
	else if (currentPos.x - nextPos.x > 0)
	{
		direction = Vector2i(-1, 0);
	}
	else if (currentPos.y - nextPos.y < 0)
	{
		direction = Vector2i(0, 1);
	}
	else if (currentPos.y - nextPos.y > 0)
	{
		direction = Vector2i(0, -1);
	}
	else if(currentPos.x - nextPos.x == 0 && currentPos.y - nextPos.y == 0)
	{
		direction = Vector2i(0, 0);
	}*/
}

void GhostMovementComponent::Update()
{
	/*canMove = true;

	targetPos = Vector2u(owner->GetLevel()->GetPacMan()->GetPosition().x, owner->GetLevel()->GetPacMan()->GetPosition().y);
	SetPath();
	if (!TryGetNextPos())
	{
		ComputeNewDirection();
		__super::Update();
	}
	ResetPath();*/
}
