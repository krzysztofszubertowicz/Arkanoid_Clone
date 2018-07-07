#include "paddle.h"
#include <SFML/Graphics.hpp>
#include <iostream>
paddle::paddle()
{
	body.setFillColor(sf::Color::Blue);
	body.setPosition({ 400,600 - 30 });
	body.setSize({ 50,10 });
}
void paddle::changeBackSize()
{
	body.setSize({ 50,10 });
}
void paddle::movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		body.move(-movement_speed.x, movement_speed.y);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		body.move(movement_speed.x,movement_speed.y);
	}
	if (body.getPosition().x < 0)
	{
		body.move(movement_speed.x, movement_speed.y);
	}
	else if (body.getPosition().x > 800-this->body.getSize().x)
	{
		body.move(-movement_speed.x, movement_speed.y);
	}
}
void paddle::draw(sf::RenderWindow & window)
{
	window.draw(body);
}
sf::RectangleShape paddle::get_shape()
{
	return body;
}
ball::ball()
{
	this->body.setFillColor(sf::Color::Green);
	this->body.setSize({ 10,10 });
	this->body.setPosition(400, 220);

}
void ball::moving(paddle & paddle)
{
	this->body.move(ball_droping);
	if (this->body.getPosition().x < 0)
	{
		this->ball_droping.x = - ball_droping.x;
	}
	if (this->body.getPosition().x > 800-(this->body.getSize().x))
	{
		this->ball_droping.x =- ball_droping.x;
	}
	sf::FloatRect paddle_(paddle.get_shape().getPosition(), paddle.get_shape().getSize());
	sf::FloatRect ball_(this->get_shape().getPosition(), this->get_shape().getSize());
	if (paddle_.intersects(ball_))
	{
		this->ball_droping.y = -ball_droping.y;
	}
	else if (this->body.getPosition().y < 0)
	{
		this->ball_droping.y = -ball_droping.y;
	}
}

block::block(sf::Vector2f where_to_Draw)
{
	body.setFillColor(sf::Color::Yellow);
	body.setSize({ 30,30 });
	body.setPosition(where_to_Draw);
}
void block::draw(sf::RenderWindow & window)
{
	window.draw(body);
}
void block::collision(ball & ball)
{
	sf::FloatRect block(body.getPosition(), body.getSize());
	sf::FloatRect ball_(ball.get_shape().getPosition(),ball.get_shape().getSize());
	if (block.intersects(ball_))
	{
		ball.ball_droping.y = -ball.ball_droping.y;
		this->body.setPosition({ 202020,2020 });
		
	}
}
void strong_block::collision_(ball & ball)
{
	sf::FloatRect block(body.getPosition(), body.getSize());
	sf::FloatRect ball_(ball.get_shape().getPosition(), ball.get_shape().getSize());
	if (block.intersects(ball_))
	{
		ball.ball_droping.y = -ball.ball_droping.y;
		this->hp -= 1;
		if (this->hp == 0)
		{
		this->body.setPosition({ 202020,2020 });
		}

	}

}
int strong_block::get_hp()
{
	return hp;
}
