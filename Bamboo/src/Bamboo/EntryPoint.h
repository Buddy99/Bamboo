#pragma once

#ifdef BM_PLATFORM_WINDOWS

extern Bamboo::Application* Bamboo::CreateApplication();

int main(int argc, char** argv)
{
	Bamboo::Log::Init();		// Initialize Logger
	BM_CORE_WARN("Initialized Log!");
	int a = 5;
	BM_INFO("Hello from Bamboo. Var={0}", a);
	auto app = Bamboo::CreateApplication();	// -> defined by Client
	app->Run();
	delete app;
}

#endif