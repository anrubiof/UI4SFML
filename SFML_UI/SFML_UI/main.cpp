#include <SFML/Graphics.hpp>
#include "iostream"
#include "IClickable.h"
#include "SFMLButton.h"
#include "SFMLCanvas.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

	SFMLCanvas *canvas = new SFMLCanvas(&window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		canvas->drawAll();
		window.display();
	}

	return 0;
}