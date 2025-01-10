#include "PacMan.h"
#include "InputManager.h"
#include "ColliderComponent.h"
#include "TextureManager.h"
#include "Ghost.h"
#include "Game.h"

PacMan::PacMan(Level* _level, const Vector2f& _shapeSize)
				: Entity(_level, "Pacman/Moving/PacMan_Moving", _shapeSize, ET_PACMAN)
{
	movement = new PlayerMovementComponent(this);
	life = new LifeComponent(this);
	animation = new AnimationComponent(this,Vector2i(texture.getSize()), Vector2i(3,1), 1.0f);
	animation->SetCurrentFrame(Vector2i(1,0));
	collider->AddCallback(ET_GHOST, [&](Entity* _entity) { EatGhost(_entity); });
	collider->AddCallback(ET_EATABLE, [&](Entity* _entity) { EatEatable(_entity); });
	collider->AddCallback(ET_APPLE, [&](Entity* _entity) { EatApple(_entity); });
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

void PacMan::EatGhost(Entity* _entity)
{
	if (Ghost* _ghost = dynamic_cast<Ghost*>(_entity))
	{
		if (_ghost->GetIsVulnerable())
		{
			_ghost->Destroy();
		}
	}
}

void PacMan::EatEatable(Entity* _entity)
{
	if (Food* _food = dynamic_cast<Food*>(_entity))
	{
		RetrieveScore(_food);
		_food->AddToRemove();
		//level->RemoveEatable(_food);
	}
}

void PacMan::EatApple(Entity* _entity)
{
	level->ActiveVulnerableEvent();
	if (Food* _food = dynamic_cast<Food*>(_entity))
	{
		RetrieveScore(_food);
	}
}

void PacMan::RetrieveScore(Food* _food)
{
	Game::GetInstance().AddScore(_food->GetPoints());
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