#pragma once

#include "CoreMinimal.h"

struct Node
{
	Vector2u position;
	u_int g;
	u_int h;
	Node* parent;

private:
	inline u_int Heuristic(const Vector2u& _posA, const Vector2u& _posB)
	{
		return abs(static_cast<int>(_posA.x - _posB.x)) + abs(static_cast<int>(_posA.y - _posB.y));
	}
public:
	Node(const Vector2u& _position, const Vector2u& _end, Node* _parent)
	{
		position = _position;
		g = _parent ? _parent->g + 1 : 0;
		h = Heuristic(_position, _end);
		parent = _parent;
	}

	inline u_int GetF() const
	{
		return g + h;
	}
};