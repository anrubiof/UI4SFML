#pragma once
#include "IClickable.h"
#include "IDrawable.h"
#include <stdint.h>
#include <SFML/Graphics.hpp>
class SFMLButton : public IClickable, public IDrawable
{
	public:

		// Constructors
		SFMLButton();
		SFMLButton(float height, float width);
		SFMLButton(float height, float width, float x, float y);

		// Destructor
		~SFMLButton();

		// Methods
		// IClickable Methods
		void onClick();
		void onHover();
		bool isHovered(sf::RenderWindow *);

		// IDrawable
		void draw(sf::RenderWindow *);
		void highlight(sf::RenderWindow *);

		void setX(float x);
		float getX() const;

		void setY(float y);
		float getY() const;

		void setHeight(float height);
		float getHeight() const;

		void setWidth(float width);
		float getWidth() const;

	private:

		// Attributes
		int x_ = 0;
		int y_ = 0;

		int height_ = 0;
		int width_	= 0;


};

