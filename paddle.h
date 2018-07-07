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
	void draw(sf::RenderWindow & window); //draw paddle
	void movement();				//A->left,D->right movement
	void changeBackSize();        //changing size to default within 'x' seconds after taking an upgrade item.
};
class block;
class strong_block;					//stronger blocks -> requires 3 hits to be crashed 
class ball: public paddle {
	friend class block;
	friend class strong_block;
protected:
	sf::Vector2f ball_droping{ 1,1 };   //Vector that defines position change per update
public:
	ball();
	void moving(paddle & paddle);		//Changing Y axis when intersects the paddle
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
	void collision_(ball & ball);      //collision with the ball it has to be done 3 times to crash the strong block
	int get_hp();						//return hp

};
#endif