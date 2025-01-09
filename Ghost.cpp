#include "Ghost.h"
#include "InputManager.h"
#include "PacMan.h"

Ghost::Ghost(Level* _level, const Vector2f& _shapeSize) 
			: Food(_level, "Ghosts/Blue/BlueGhost_Moving", _shapeSize, 1000, FT_GHOST)
{
	isVulnerable = false;
	movement = new GhostMovementComponent(this);

	animation = new AnimationComponent(this, Vector2i(texture.getSize()), Vector2i(4, 1), 1.0f);
	animation->SetCurrentFrame(Vector2i(1, 0));
}

Ghost::~Ghost()
{
	delete movement;
	delete animation;
}

void Ghost::Update()
{
	movement->Update();
}

bool Ghost::Eat(Entity* _entity)
{
	if (PacMan* _pacMan = dynamic_cast<PacMan*>(_entity))
	{
		if (isVulnerable)
		{
			return __super::Eat(_entity);
		}
		else
		{
			_pacMan->Death();
			return false;
		}

	}
	return true;
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