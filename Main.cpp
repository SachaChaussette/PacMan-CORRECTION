#include "Level.h"
#include "InputManager.h"


int main()
{
    #pragma warning (push)
    #pragma warning (disable 4275)
    Level _level = Level("SmallMap");
    
    RenderWindow _window(VideoMode({ _level.GetMapSize().x, _level.GetMapSize().y }), "PacMan");

    while (_window.isOpen())
    {
        InputManager::GetInstance().ConsumeInputs(_window);

        _window.clear();
        _level.Display(_window);
        _window.display();
    }

    #pragma warning (pop)

    return EXIT_SUCCESS;
}


/*

	1- Lecture fichier .txt
    2- Génération Entité
    3- Boucle affichage entité

    1- Déplacement du PacMan
    2- Supprimer les Pastilles
    3- Ajouter du score
    4- Collision avec les murs



*/