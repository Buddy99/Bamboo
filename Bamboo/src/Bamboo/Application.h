#pragma once

#include "Core.h"
#include "Timing.h"
#include "GUI.h"

namespace Bamboo
{
	class BAMBOO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		virtual void Update(double deltaTime);	// Virtual so that the Sandbox can override it

	protected:
		inline static GUI* gui;

	private:
	};

	// To be defined by Client
	Application* CreateApplication();
}


