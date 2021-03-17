#pragma once

#include "Core.h"

namespace Bamboo
{
	class BAMBOO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined by Client
	Application* CreateApplication();
}


