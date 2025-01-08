#include "Level.h"
#include "InputManager.h"

#define MAP_SIZE_X 28
#define MAP_SIZE_Y 28
#define TILE_SIZE 20

int main()
{
    #pragma warning (push)
    #pragma warning (disable 4275)

    ContextSettings _settings;
    _settings.antiAliasingLevel = 8;
    RenderWindow _window(VideoMode(Vector2u(MAP_SIZE_X * TILE_SIZE, MAP_SIZE_Y * TILE_SIZE)), "Pac Man", State::Windowed, _settings);
    Level _level = Level("SmallMap", _window);  

    while (_window.isOpen())
    {
        InputManager::GetInstance().ConsumeInputs(_window);

        _window.clear();
        _level.Update();
        _window.display();
        SLEEP(500ms);
    }

    #pragma warning (pop)

    return EXIT_SUCCESS;
}


/*

	1- Lecture fichier .txt          ✅
    2- Génération Entité             ✅
    3- Boucle affichage entité       ✅

    1- Déplacement du PacMan         ✅
    2- Supprimer les Pastilles
    3- Ajouter du score
    4- Collision avec les murs


    


*/

/*
*      TODO LIST
*
*   
*
*
* 
*
*
*/