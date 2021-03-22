#include "SFMLCanvas.h"
#include "SFMLButton.h"
#include "IClickable.h"
#include "iostream"
#include "pugixml-1.11/pugixml-1.11/src/pugixml.hpp"
#include "pugixml-1.11/pugixml-1.11/src/pugixml.cpp"
#include "pugixml-1.11/pugixml-1.11/src/pugiconfig.hpp"

using namespace std;

SFMLCanvas::SFMLCanvas(sf::RenderWindow * renderWindow)
{
	renderWindow_ = renderWindow;

	SFMLButton *button;

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("UI.xml");
	pugi::xml_node document = doc.child("document");

	for (const pugi::xml_node &child : document) {
		std::string childName = static_cast<std::string>(child.name());
		if (childName == "button")
		{
			float x = std::stof(static_cast<std::string>(child.attribute("x").value()));
			float y = std::stof(static_cast<std::string>(child.attribute("y").value()));
			float height = std::stof(static_cast<std::string>(child.attribute("height").value()));
			float width = std::stof(static_cast<std::string>(child.attribute("width").value()));

			button = new SFMLButton(height, width, x, y);

			drawablesVector_.push_back(button);
			clickablesVector_.push_back(button);
		}
	}
}


SFMLCanvas::~SFMLCanvas()
{
}

sf::RenderWindow * SFMLCanvas::getRenderWindow() const
{
	return renderWindow_;
}

void SFMLCanvas::drawAll()
{
	for (int i = 0; i < drawablesVector_.capacity(); i++)
	{
		drawablesVector_[i]->draw(renderWindow_);
	}

	for (int i = 0; i < clickablesVector_.capacity(); i++)
	{
		if (clickablesVector_[i]->isHovered(renderWindow_)) {
			static_cast<SFMLButton*> (drawablesVector_[i])->highlight(renderWindow_);
		}
	}
}


