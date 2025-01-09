#pragma once

#include "Node.h"
#include "Level.h"

class AstarAlgo
{
	Level* level;

public:
	AstarAlgo(Level* _level);

private:
	bool IsValid(const Vector2u& _position) const;
	static bool CompareNodes(Node* _first, Node* _second);
	u_int ComputeIndex(const Vector2u& _position) const;
	vector<Vector2u> GetNeighbors(const Vector2u& _position) const;
	vector<Vector2u> ReconstructPath(Node* _node) const;
	void Erase(const unordered_map<u_int, Node*>& _allNodes) const;

public:
	vector<Vector2u> FindPath(const Vector2u& _start, const Vector2u& _end);
};

