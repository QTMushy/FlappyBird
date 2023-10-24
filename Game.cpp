#include "Game.h"
#include "Global.h"
#include"Pipes.h"
using namespace sf;
Game::Game(RenderWindow& window): win(window), isEnteredPressed(false),runnig(true),pipe_counter(71),pipe_spawn_time(70)
{
	win.setFramerateLimit(60);
	bg_texture.loadFromFile("Assets/bg.png");
	bg_sprite.setTexture(bg_texture);
	bg_sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);
	bg_sprite.setPosition(0.f, -250.f);

	ground.loadFromFile("Assets/ground.png");
	ground_sprite1.setTexture(ground);
	ground_sprite2.setTexture(ground);
	ground_sprite1.setScale(SCALE_FACTOR, SCALE_FACTOR);
	ground_sprite2.setScale(SCALE_FACTOR, SCALE_FACTOR);
	ground_sprite1.setPosition(0.f, 578.f);
	ground_sprite2.setPosition(ground_sprite1.getGlobalBounds().width, 578.f);
	Pipes::loadTextures();



}
void Game::StartGameLoop()
{
	Clock clock;
	while (win.isOpen())
	{
		Time dt = clock.restart();
		Event event;
		while (win.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				win.close();
			}
			if (event.type == Event::KeyPressed && runnig)
			{
				if (event.key.code == Keyboard::Enter && !isEnteredPressed)
				{
					isEnteredPressed = true;
					bird.shouldFly(true);
				}
				if (event.key.code == Keyboard::Space && isEnteredPressed)
				{
					
 					bird.flapBird(dt);

				}

			}
		}
		doProcessing(dt);
		
		draw();

		win.display();
	}
}

void Game::draw()
{
	win.draw(bg_sprite);
	for (Pipes& pipe : pipes)
	{
		win.draw(pipe.sprite_down);
		win.draw(pipe.sprite_up);
	}
	win.draw(ground_sprite1);
	win.draw(ground_sprite2);
	win.draw(bird.bird_sprite);
}

void Game::moveGround(sf::Time& dt)
{
	ground_sprite1.move(-move_speed * dt.asSeconds(), 0);
	ground_sprite2.move(-move_speed * dt.asSeconds(), 0);

	if (ground_sprite1.getGlobalBounds().left + ground_sprite1.getGlobalBounds().width < 0)
	{
		ground_sprite1.setPosition(ground_sprite2.getGlobalBounds().left + ground_sprite2.getGlobalBounds().width, 578);
	}
	if (ground_sprite2.getGlobalBounds().left + ground_sprite2.getGlobalBounds().width < 0)
	{
		ground_sprite2.setPosition(ground_sprite1.getGlobalBounds().left + ground_sprite1.getGlobalBounds().width, 578);
	}
}
void Game::doProcessing(Time& dt)
{
	if (isEnteredPressed)
	{
		moveGround(dt);
		if (pipe_counter > pipe_spawn_time)
		{
			
			pipes.push_back(Pipes(dist(rd)));
			pipe_counter = 0;
		}
		pipe_counter++;

		for (int i = 0; i < pipes.size(); i++)
		{
			pipes[i].update(dt);
			if (pipes[i].getRightBounds() < 0)
			{
				pipes.erase(pipes.begin() + i);
			}

		}

	}
	bird.update(dt);
}
