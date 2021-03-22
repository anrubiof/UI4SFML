#pragma once
#include <SFML/Graphics.hpp>
#include "IDrawable.h"
#include "IClickable.h"

class SFMLCanvas
{
public:

	// Constructors
	SFMLCanvas(sf::RenderWindow * renderWindow);

	// Destructor
	~SFMLCanvas();

	// Methods
	sf::RenderWindow * getRenderWindow() const;
	void drawAll();

private:

	// Attributes 
	sf::RenderWindow *renderWindow_ = nullptr;

	std::vector<IDrawable *>  drawablesVector_  = std::vector<IDrawable *>(0);
	std::vector<IClickable *> clickablesVector_ = std::vector<IClickable *>(0);

	// Methods
};

