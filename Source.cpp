#include <SFML/Graphics.hpp>
#include "Global.h"
#include "Game.h"
using namespace sf;

int main()
{

    RenderWindow window(VideoMode(WIN_WIDTH,WIN_HEIGHT),"Flappy Bird");
    Game game(window);
    game.StartGameLoop();
    return 0;

}                            