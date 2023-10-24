#include "Pipes.h"
#include"Global.h"
using namespace sf;
Pipes::Pipes(int y_pos)
{
	sprite_down.setTexture(texture_down);
	sprite_up.setTexture(texture_up);

	sprite_down.setScale(SCALE_FACTOR, SCALE_FACTOR);
	sprite_up.setScale(SCALE_FACTOR, SCALE_FACTOR);

	sprite_up.setPosition(WIN_WIDTH, y_pos);
	sprite_down.setPosition(WIN_WIDTH, y_pos-pipe_distance-sprite_up.getGlobalBounds().height);



}
void Pipes::loadTextures()
{
	texture_up.loadFromFile("Assets/pipe.png");
	texture_down.loadFromFile("Assets/pipedown.png");

	

}
void Pipes::update(Time& dt)
{
	sprite_up.move(-move_speed * dt.asSeconds(), 0.f);
	sprite_down.move(-move_speed * dt.asSeconds(), 0.f);

}
float Pipes::getRightBounds()
{
	return sprite_down.getGlobalBounds().left+sprite_down.getGlobalBounds().width;
}

Texture Pipes::texture_down, Pipes::texture_up;
int Pipes::pipe_distance = 100, Pipes::move_speed = 400;
