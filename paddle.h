#pragma once
#include <SFML/Graphics.hpp>
#ifndef paddle_h
#define paddle_h
#include "upgrade.h"
class upgrade_item;
class paddle {
	friend class upgrade_item;
protected:
	sf::RectangleShape body;
	sf::Vector2f movement_speed{ 2,0 };
public:
	paddle();
	sf::RectangleShape get_shape();	//Return body
	void draw(sf::RenderWindow & window); //draw_paddle
	void movement();				//A,D movement
	void changeBackSize();
};
class block;
class strong_block;
class ball: public paddle {
	friend class block;
	friend class strong_block;
protected:
	sf::Vector2f ball_droping{ 1,1 };
public:
	ball();
	void moving(paddle & paddle);
};
class block {
public:
	sf::RectangleShape body;
	block(sf::Vector2f where_to_Draw);
	void collision(ball & ball);
	void draw(sf::RenderWindow & window);


};
class strong_block : public block {
protected:
	int hp = 3;
public:
	using block::block;
	void collision_(ball & ball);
	int get_hp();

};
#endif