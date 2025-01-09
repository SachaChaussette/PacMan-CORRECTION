#include "GhostMovementComponent.h"
#include "AstarAlgo.h"
#include "Ghost.h"


GhostMovementComponent::GhostMovementComponent(Entity* _owner) : MovementComponent(_owner)
{
	path = queue<Vector2u>();
	targetPos = Vector2u(owner->GetLevel()->GetPacMan()->GetPosition().x, owner->GetLevel()->GetPacMan()->GetPosition().y);
}

bool GhostMovementComponent::RetrieveNextPos()
{
	if (path.empty()) return false;

	for (u_int _index = 0; _index < speed; _index++)
	{
		targetPos = path.front();
		path.pop();
	}

	return true;
}

bool GhostMovementComponent::TryGetNextPos()
{
	if (targetPos != Vector2u())
	{
		if (!RetrieveNextPos()) return false;
	}
	return true;
}

void GhostMovementComponent::SetTargetPosition(const Vector2u& _targetPos)
{
	AstarAlgo _astar = AstarAlgo(owner->GetLevel());

	vector<Vector2u> _collection = _astar.FindPath(Vector2u(owner->GetPosition()), _targetPos);
	for (const Vector2u& _value : _collection)
	{
		path.push(_value);
	}
}

void GhostMovementComponent::MoveToTarget()
{
	if (!TryGetNextPos()) return;

	owner->SetPosition(Vector2f(targetPos));
	targetPos = Vector2u();
}

void GhostMovementComponent::Update()
{
	__super::Update();

	//targetPos = Vector2u(owner->GetLevel()->GetPacMan()->GetPosition().x, owner->GetLevel()->GetPacMan()->GetPosition().y);
	//SetTargetPosition(targetPos);
    //MoveToTarget();
}
