#include "PacMan.h"
#include "InputManager.h"
#include "ColliderComponent.h"
#include "TextureManager.h"

PacMan::PacMan(Level* _level, const Vector2f& _shapeSize)
				: Entity(_level, "Pacman/Moving/PacMan_Moving", _shapeSize, CT_NONE)
{
	movement = new PlayerMovementComponent(this);
	life = new LifeComponent(this);
	animation = new AnimationComponent(this,Vector2i(texture.getSize()), Vector2i(3,1), 1.0f);
	animation->SetCurrentFrame(Vector2i(1,0));

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
	_manager.BindAction( [&]() 
		{ 
			movement->ToggleMoveStatus(); 
			animation->ToggleRunStatus();
			animation->SetCurrentFrame(Vector2i(1, 0));
		}, 
	Code::Space);
	_manager.BindAction( [&]() { movement->SetDirection(Vector2i(0, -1)); }, { Code::Z, Code::Up });
	_manager.BindAction( [&]() { movement->SetDirection(Vector2i(0, 1)); } , { Code::S, Code::Down });
	_manager.BindAction( [&]() { movement->SetDirection(Vector2i(-1, 0)); }, { Code::Q, Code::Left });
	_manager.BindAction( [&]() { movement->SetDirection(Vector2i(1, 0)); },	 { Code::D, Code::Right });
}

void PacMan::Update()
{
	//TextureManager::GetInstance().UpdateSpriteIndex(*shape, spriteIndex, 3,1);
	movement->Update();
	life->Update();
	animation->Update();
}

void PacMan::Death()
{
	life->RemoveLife();
	level->Respawn(this);
}

// Systeme d'animation de pacman setTextureRect
// Game