#include "Ghost.h"
#include "InputManager.h"
#include "PacMan.h"

Ghost::Ghost(Level* _level, const Vector2f& _shapeSize) 
			: Food(_level, "Ghosts/Blue/BlueGhost_Moving", _shapeSize, 1000, ET_GHOST)
{
	isVulnerable = false;
	movement = new GhostMovementComponent(this);

	//collider->AddCallback(CT_BLOCK, [&]() { ComputeNewDirection();  });
	animation = new AnimationComponent(this, Vector2i(texture.getSize()), Vector2i(4, 1), 1.0f);
	animation->SetCurrentFrame(Vector2i(1, 0));
	collider->AddCallback(ET_GHOST, [&](Entity* _entity) { EatPacMan(_entity); });

	SetupInputs();
}

Ghost::~Ghost()
{
	delete movement;
	delete animation;
}


void Ghost::EatPacMan(Entity* _entity)
{
	if (isVulnerable) return;
	if (PacMan* _pacMan = static_cast<PacMan*>(_entity))
	{
		_pacMan->Death();
	}
}

void Ghost::Update()
{
	movement->Update();
}


void Ghost::Destroy()
{
	if(isVulnerable)
	{
		__super::Destroy();
	}
}

void Ghost::SetupInputs()
{
	InputManager& _manager = InputManager::GetInstance();
	_manager.BindAction([&]()
		{
			movement->ToggleMoveStatus();
		},
		Code::Space);
}
