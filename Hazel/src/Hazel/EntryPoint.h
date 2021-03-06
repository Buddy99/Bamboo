#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{
	Hazel::Log::Init();		// Initialize Logger
	HZ_CORE_WARN("Initialized Log!");
	int a = 5;
	HZ_INFO("Hello from Hazel. Var={0}", a);
	auto app = Hazel::CreateApplication();	// -> defined by Client
	app->Run();
	delete app;
}

#endif