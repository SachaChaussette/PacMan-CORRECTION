#include "AstarAlgo.h"

AstarAlgo::AstarAlgo(Level* _level)
{
	level = _level;
}

bool AstarAlgo::IsValid(const Vector2u& _position) const
{
	return _position.x >= 0 && _position.y >= 0 
		&& _position.x < level->GetMapSize().x && _position.y < level->GetMapSize().y;
}

bool AstarAlgo::CompareNodes(Node* _first, Node* _second)
{
	return _first->GetF() > _second->GetF();
}

u_int AstarAlgo::ComputeIndex(const Vector2u& _position) const
{
	return _position.y * level->GetMapSize().x + _position.x;
}

vector<Vector2u> AstarAlgo::GetNeighbors(const Vector2u& _position) const
{
	return
	{
		Vector2u(_position.x + 1, _position.y),
		Vector2u(_position.x - 1, _position.y),
		Vector2u(_position.x, _position.y + 1),
		Vector2u(_position.x, _position.y - 1),
	};
}

vector<Vector2u> AstarAlgo::ReconstructPath(Node* _node) const
{
	vector<Vector2u> _path;

	while (_node)
	{
		_path.insert(_path.begin(), _node->position); 
		_node = _node->parent;
	}

	return _path;
}

void AstarAlgo::Erase(const unordered_map<u_int, Node*>& _allNodes) const
{
	for (const pair<u_int, Node*>& _pair : _allNodes)
	{
		delete _pair.second;
	}
}

vector<Vector2u> AstarAlgo::FindPath(const Vector2u& _start, const Vector2u& _end)
{
	priority_queue<Node*, vector<Node*>, function<bool(Node*, Node*) >> _openList(CompareNodes);
	unordered_map<u_int, Node*> _allNodes;
	unordered_map<u_int, bool> _closedList;

	Node* _startNode = new Node(_start, _end, nullptr);
	_openList.push(_startNode);
	_allNodes[ComputeIndex(_start)] = _startNode;

	while (!_openList.empty())
	{
		Node* _currentNode = _openList.top(); 
		_openList.pop();

		if (_currentNode->position == _end)
		{
			const vector<Vector2u>& _finalPath = ReconstructPath(_currentNode);

			Erase(_allNodes);

			return _finalPath;
		}

		_closedList[ComputeIndex(_currentNode->position)] = true;

		for (const Vector2u& _neighborPosition : GetNeighbors(_currentNode->position))
		{
			const u_int& _neighborIndex = ComputeIndex(_neighborPosition);
			if (IsValid(_neighborPosition) && !_closedList[_neighborIndex])
			{
				Node* _neighbor = new Node(_neighborPosition, _end, _currentNode);

				if (_allNodes.find(_neighborIndex) == _allNodes.end() || _neighbor->GetF() < _allNodes[_neighborIndex]->GetF())
				{
					_openList.push(_neighbor);
					_allNodes[_neighborIndex] = _neighbor;
				}
				else
				{
					delete _neighbor;
				}
			}
		}
	}
	Erase(_allNodes);

	return vector<Vector2u>();
}
