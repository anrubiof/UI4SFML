#include "SFMLButton.h"
SFMLButton::SFMLButton()
{
	x_ = 0;
	y_ = 0;

	height_ = 0;
	width_ = 0;

}

SFMLButton::SFMLButton(float height, float width)
{
	x_ = 0;
	y_ = 0;

	height_ = height;
	width_ = width;
}

SFMLButton::SFMLButton(float height, float width, float x, float y)
{
	x_ = x;
	y_ = y;

	height_ = height;
	width_ = width;
}


SFMLButton::~SFMLButton()
{
}

void SFMLButton::onClick()
{

}

void SFMLButton::onHover()
{
}

bool SFMLButton::isHovered(sf::RenderWindow * window) {
	sf::Vector2i localPosition = sf::Mouse::getPosition(* window); // window is a sf::Window
	int localX = localPosition.x;
	int localY = localPosition.y;

	if (!((localX<x_)||(localY<y_)||(localX>(x_+width_))||(localY>(y_+height_)))) {
		return true;
	}
	return false;
}

void SFMLButton::draw(sf::RenderWindow * window)
{
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(width_, height_));
	rectangle.setOutlineColor(sf::Color::Black);
	rectangle.setOutlineThickness(5);
	rectangle.setPosition(x_, y_);
	window->draw(rectangle);
}

void SFMLButton::highlight(sf::RenderWindow * window)
{
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(width_, height_));
	rectangle.setOutlineColor(sf::Color::Green);
	rectangle.setOutlineThickness(5);
	rectangle.setPosition(x_, y_);
	window->draw(rectangle);
}

void SFMLButton::setX(float x)
{
	x_ = x;
}

float SFMLButton::getX() const
{
	return x_;
}

void SFMLButton::setY(float y)
{
	y_ = y;
}

float SFMLButton::getY() const
{
	return y_;
}

void SFMLButton::setHeight(float height)
{
	height_ = height;
}

float SFMLButton::getHeight() const
{
	return height_;
}

void SFMLButton::setWidth(float width)
{
	width_ = width;
}

float SFMLButton::getWidth() const
{
	return width_;
}

