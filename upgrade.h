#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "paddle.h"
#ifndef upgrade_h
#define upgrade_h
class upgrade_item {
	sf::RectangleShape body;
public:
	sf::RectangleShape get_body();
	upgrade_item();
};
#endif // !upgrade_h
