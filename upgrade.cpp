#include "paddle.h"
#include "upgrade.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include <cstdlib>
#include <ctime>

upgrade_item::upgrade_item()
{
	srand(time(NULL));
	body.setSize({ 40,20 });
	sf::Vector2f random_pos(float((std::rand() % 700) + 1), 0.f);
	body.setPosition(random_pos);
	body.setFillColor(sf::Color::White);
}
void upgrade_item::movement()
{
	body.move({ 0,1 });
}

void upgrade_item::intersectWithPaddle(paddle & paddle,sf::Clock&clock)
{
	sf::FloatRect upgradeItem(body.getPosition(), body.getSize());
	sf::FloatRect paddle_(paddle.get_shape().getPosition(), paddle.get_shape().getSize());
	sf::Vector2f previous_size(paddle.body.getSize().x, paddle.body.getSize().y);
	if (upgradeItem.intersects(paddle_))
	{
		body.setPosition({ 202020,202020 });
		paddle.body.setSize({ paddle.body.getSize().x + 70, paddle.body.getSize().y });
		clock.restart();
	}

}
void upgrade_item::draw(sf::RenderWindow&window)
{
	window.draw(body);
}
