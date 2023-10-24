
#include<SFML/Graphics.hpp>
#include "Bird.h"
#include<vector>
#include"Pipes.h"
#include<random>
using namespace sf;
class Game
{
public:
	Game(RenderWindow& window);
	RenderWindow& win;
	void StartGameLoop();
	
private:
	Texture bg_texture,ground;
	Sprite bg_sprite,ground_sprite1,ground_sprite2;
	const int move_speed = 270;
	void draw();
	Bird bird;
	bool isEnteredPressed;
	bool runnig;
	void moveGround(sf::Time&);
	void doProcessing(Time&);
	int pipe_counter, pipe_spawn_time;
	std::vector<Pipes> pipes;
	std::random_device rd;
	std::uniform_int_distribution<int> dist{ 250,550 };

	 
};

