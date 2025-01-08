#include "Game.h"

int main()
{
    #pragma warning (push)
    #pragma warning (disable 4275)

    Game::GetInstance().SetWindow(Vector2u(MAP_SIZE_X, MAP_SIZE_Y),Vector2u(TILE_SIZE_X, TILE_SIZE_Y),"Pac Man");

    Game::GetInstance().LoadLevel("SmallMap");

    Game::GetInstance().Loop();

    #pragma warning (pop)

    return EXIT_SUCCESS;
}


/*

    1- Lecture fichier .txt          ✅
    2- Génération Entité             ✅
    3- Boucle affichage entité       ✅

    1- Déplacement du PacMan         ✅
    2- Supprimer les Pastilles       ✅
    3- Ajouter du score              ✅
    4- Collision avec les murs       ✅

    1- Réparer les Mouvements        ✅
    2- Animation de PacMan           ✅
    3- Game                          ✅

*/
