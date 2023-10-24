#include "Bird.h"
#include<SFML/Graphics.hpp>
#include "Global.h"
using namespace sf;

Bird::Bird() :
	gravity(10),
	flap_speed(250),
	veclocity_y(0),
	anim_counter(0),
	should_fly(false),
	texture_switch(1)
{
	bird_texture[0].loadFromFile("Assets/birddown.png");
	bird_texture[1].loadFromFile("Assets/birdup.png");
	bird_sprite.setTexture(bird_texture[0]);
	bird_sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);
	resetBirdPosition();


}

void Bird::update(Time& dt)
{
	if (bird_sprite.getGlobalBounds().top < 548 && should_fly == true)
	{
		if (anim_counter == 5)
		{
			bird_sprite.setTexture(bird_texture[texture_switch]);
			if (texture_switch) texture_switch = 0;
			else texture_switch = 1;
			anim_counter = 0;

		}
		anim_counter++;
		veclocity_y += gravity * dt.asSeconds();
		bird_sprite.move(0, veclocity_y);

		if (bird_sprite.getGlobalBounds().top < 0)
		{
			bird_sprite.setPosition(100, 0);
		}
	}

}
void Bird::flapBird(Time&dt)
{
	veclocity_y = -flap_speed * dt.asSeconds();

}
void Bird::resetBirdPosition()
{
	bird_sprite.setPosition(100, 50);
	veclocity_y = 0;
}
void Bird::shouldFly(bool should_fly)
{
	this->should_fly = should_fly;
}
float Bird::getRightBound()
{
	return bird_sprite.getGlobalBounds().left+bird_sprite.getGlobalBounds().width;
}
