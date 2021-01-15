#include <iostream>
#include "Game/Game.h"

int main(int argc, char** argv) {
    Game game; //Класс игры

    game.Initialize();

    game.Run();

    game.Destroy();

    return 0;
}