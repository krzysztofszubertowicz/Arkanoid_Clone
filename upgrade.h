#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "paddle.h"
#ifndef upgrade_h
#define upgrade_h
class paddle;
class upgrade_item {
public:
	sf::RectangleShape body;
	sf::RectangleShape get_body();
	upgrade_item();
	void movement();
	void intersectWithPaddle(paddle & paddle,sf::Clock&clock);
	void draw(sf::RenderWindow &window);
};
#endif // !upgrade_h
