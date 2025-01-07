#include "PacMan.h"
#include "InputManager.h"

PacMan::PacMan(const string& _path, const Vector2f& _shapeSize) : Entity(_path, _shapeSize)
{
	movement = new MovementComponent(this);
	life = new LifeComponent(this);

	SetupInputs();
}

PacMan::~PacMan()
{
	delete movement;
	delete life;
}

void PacMan::SetupInputs() 
{
	InputManager& _manager = InputManager::GetInstance();
	
	_manager.BindAction(Code::Z, [&]() { movement->Move(Vector2i(0, -1)); });
	_manager.BindAction(Code::S, [&]() { movement->Move(Vector2i(0, 1)); });
	_manager.BindAction(Code::Q, [&]() { movement->Move(Vector2i(1, 0)); });
	_manager.BindAction(Code::D, [&]() { movement->Move(Vector2i(-1, 0)); });
}

void PacMan::MoveUp()
{
}

void PacMan::MoveDown()
{
}

void PacMan::MoveLeft()
{
}

void PacMan::MoveRight()
{
}
