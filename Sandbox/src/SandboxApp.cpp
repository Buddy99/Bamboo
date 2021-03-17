#include <Bamboo.h>

// Important note: the sandbox project needs to be set as Startup project, so that the build order is correct

class Sandbox : public Bamboo::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Bamboo::Application* Bamboo::CreateApplication()
{
	return new Sandbox();
}