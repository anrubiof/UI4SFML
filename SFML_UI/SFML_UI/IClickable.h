#include <SFML/Graphics.hpp>
#pragma once
class IClickable
{
	public:

	virtual bool isHovered(sf::RenderWindow *) = 0;
	virtual void onClick() = 0;
	virtual void onHover() = 0;
	
};