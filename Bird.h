#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Bird
{
public:
	Sprite bird_sprite;
	Bird();
	void update(Time&);
	void flapBird(Time&);
	void resetBirdPosition();
	void shouldFly(bool);
	float getRightBound();

private:
	Texture bird_texture[2];
	const int gravity;
	const int flap_speed;
	float veclocity_y;
	int anim_counter, texture_switch;
	bool should_fly;


};

