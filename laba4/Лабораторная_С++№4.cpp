#include <iostream>
#include <windows.h>
#include "Card.h"
#include "Deck.h"
#include "Game.h"
#include <time.h>

int main()
{
    setlocale(LC_ALL, "Монтекарло");
	srand(time(0));


    Game* game = new Game(4, 25, 500);

    game->Play();

    system("pause");
    return 0;

}

