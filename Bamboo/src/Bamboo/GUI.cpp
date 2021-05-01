#include "GUI.h"

namespace Bamboo
{
	GUI::GUI()
	{
		window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "GUI");
	}

	GUI::~GUI()
	{
		delete window;
	}

	bool GUI::IsWindowOpen()
	{
		return window->isOpen();
	}

	void GUI::CloseWindow()
	{
		window->close();
	}

	bool GUI::pollEvent(sf::Event& event)
	{
		return window->pollEvent(event);
	}

	void GUI::AddDrawable(sf::Drawable* drawable)
	{
		// Add drawable object
		objects.push_back(drawable);
	}

	void GUI::RemoveDrawable(sf::Drawable* drawable)
	{
		// Remove drawable object
		objects.erase(std::find(objects.begin(), objects.end(), drawable));
	}

	void GUI::Render()
	{
		// Render all objects
		window->clear();
		for (auto it = objects.begin(); it != objects.end(); it++)
		{
			window->draw(**it);
		}
		window->display();
	}
}