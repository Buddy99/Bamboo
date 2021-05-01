#pragma once

#include "Core.h"
#include <SFML/Graphics.hpp>

// Abstraction Layer (The game calls my GUI functions which then call the GUI [the game can't call the GUI directly])
// If I want to change the GUI, I only have to change my GUI functions

namespace Bamboo
{
	class BAMBOO_API GUI
	{
	public:
		GUI();
		~GUI();

		bool IsWindowOpen();
		void CloseWindow();
		bool pollEvent(sf::Event& event);

		void AddDrawable(sf::Drawable* drawable);
		void RemoveDrawable(sf::Drawable* drawable);

		void Render();

	private:
		const unsigned int windowWidth = 1024;
		const unsigned int windowHeight = 840;
		sf::RenderWindow* window;
		std::vector<sf::Drawable*> objects;
	};
}


