#pragma once

#include "CoreMinimal.h"
#include "Singleton.h"

using KeyPressed = Event::KeyPressed;
using Code = Keyboard::Scancode;

class InputManager : public Singleton<InputManager>
{

	map<Code, function<void()>> callbacks;

public:

private :
	void CloseWindow(RenderWindow& _window);
public:
	void BindAction(Code _code, function<void()> _callback);
	void ConsumeInputs(RenderWindow& _window);
};

