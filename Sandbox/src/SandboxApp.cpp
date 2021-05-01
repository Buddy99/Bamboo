#include <Bamboo.h>

// Important note: the sandbox project needs to be set as Startup project, so that the build order is correct

class Sandbox : public Bamboo::Application
{
public:
	Sandbox()
		: Application()
		, quad(sf::Quads, 4)
		, movementSpeed(100.f)
	{
		// Initial Quad Position
		quad[0].position = sf::Vector2f(500.f, 500.f);
		quad[1].position = sf::Vector2f(750.f, 500.f);
		quad[2].position = sf::Vector2f(750.f, 750.f);
		quad[3].position = sf::Vector2f(500.f, 750.f);

		// Initial Quad Color
		quad[0].color = sf::Color::Red;
		quad[1].color = sf::Color::Blue;
		quad[2].color = sf::Color::Red;
		quad[3].color = sf::Color::Blue;

		gui->AddDrawable(&quad);
	}

	~Sandbox()
	{

	}

	virtual void Update(double deltaTime)
	{
		// Move the quad
		double newPos = movementSpeed * deltaTime;
		if (((int)Bamboo::Timing::GetTimeSinceStartup() % 10) >= 5)
		{
			quad[0].position = quad[0].position + sf::Vector2f(newPos, newPos);
			quad[1].position = quad[1].position + sf::Vector2f(newPos, newPos);
			quad[2].position = quad[2].position + sf::Vector2f(newPos, newPos);
			quad[3].position = quad[3].position + sf::Vector2f(newPos, newPos);
		}
		else
		{
			quad[0].position = quad[0].position - sf::Vector2f(newPos, newPos);
			quad[1].position = quad[1].position - sf::Vector2f(newPos, newPos);
			quad[2].position = quad[2].position - sf::Vector2f(newPos, newPos);
			quad[3].position = quad[3].position - sf::Vector2f(newPos, newPos);
		}
	}

private:
	sf::VertexArray quad;
	double movementSpeed;
};

Bamboo::Application* Bamboo::CreateApplication()
{
	return new Sandbox();
}