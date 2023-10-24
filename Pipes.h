#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
class Pipes{
public:
	Pipes(int);
	Sprite sprite_up, sprite_down;
	static void loadTextures();
	void update(Time&);
	float getRightBounds();
private:
	static Texture texture_down, texture_up;
	static int pipe_distance, move_speed;

};

