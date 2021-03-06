#include <Hazel.h>

// Important note: the sandbox project needs to be set as Startup project, so that the build order is correct

class Sandbox : public Hazel::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}