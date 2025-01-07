#include "InputManager.h"



void InputManager::CloseWindow(RenderWindow& _window)
{
    _window.close();
}

void InputManager::BindAction(Code _code, function<void()> _callback)
{
    callbacks.insert({ _code, _callback });
}

void InputManager::ConsumeInputs(RenderWindow& _window)
{
    while (const std::optional _event = _window.pollEvent())
    {
        if (_event->is<Event::Closed>())
        {
            CloseWindow(_window);
        }
        else if (const Event::KeyPressed* _key = _event->getIf<Event::KeyPressed>())
        {
            if (_key->scancode == Code::Escape)
            {
                CloseWindow(_window);
            }

            if (callbacks.contains(_key->scancode))
            {
                callbacks[_key->scancode]();
            }
        }


    }
}
