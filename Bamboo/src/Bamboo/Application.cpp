#include "Application.h"

namespace Bamboo
{
	Application::Application()
	{
		Timing::Init();
		gui = new GUI();
	}

	Application::~Application()
	{
		delete gui;
	}

	void Application::Run()
	{
		double previous = Timing::GetTimeSinceStartup();
		double lag = 0.0;
		double renderLag = 0.0;

		// Game Loop
		while (gui->IsWindowOpen())
		{
			double current = Timing::GetTimeSinceStartup();
			Timing::SetDeltaTime(current - previous);
			previous = current;
			lag += Timing::GetDeltaTime();
			renderLag += Timing::GetDeltaTime();

			sf::Event event;

			while (gui->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					gui->CloseWindow();
				}					
			}

			// processInput();

			// Use fixed delta time for simulation
			while (lag >= Timing::GetFixedFrameTime())
			{
				Update(Timing::GetFixedFrameTime());
				lag -= Timing::GetFixedFrameTime();
			}

			// Render at different framerates
			if (renderLag >= Timing::GetRenderFrameTime())	// if instead of while, so that Render doesn't block Update
			{
				gui->Render();
				renderLag -= Timing::GetRenderFrameTime();
			}
		}
	}

	void Application::Update(double deltaTime)
	{

	}
}