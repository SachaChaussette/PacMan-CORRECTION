#include "PacMan.h"
#include "InputManager.h"
#include "ColliderComponent.h"

PacMan::PacMan(Level* _level, const Vector2f& _shapeSize)
				: Entity(_level, "Pacman/Moving/PacMan_Moving", _shapeSize, CT_NONE)
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
	_manager.BindAction( [&]() { movement->ToggleMoveStatus(); }, Code::Space);
	_manager.BindAction( [&]() { 
		movement->SetDirection(Vector2i(0, -1)); }, { Code::Z, Code::Up });
	_manager.BindAction( [&]() { movement->SetDirection(Vector2i(0, 1)); } , { Code::S, Code::Down });
	_manager.BindAction( [&]() { movement->SetDirection(Vector2i(-1, 0)); }, { Code::Q, Code::Left });
	_manager.BindAction( [&]() { movement->SetDirection(Vector2i(1, 0)); }, { Code::D, Code::Right });
}

void PacMan::Update()
{
	movement->Update();
	life->Update();
}

// Systeme d'animation de pacman setTextureRect
// Game