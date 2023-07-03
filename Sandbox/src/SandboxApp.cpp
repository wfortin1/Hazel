#include <Hazel.h>

// Sandbox client app
class SandboxApp : public Hazel::Application
{
public: 
	SandboxApp()
	{

	}

	~SandboxApp()
	{

	}
};

// Function required to be defined by "EntryPoint.h" returns a SandboxApp
Hazel::Application* Hazel::CreateApplication()
{
	return new SandboxApp(); 
}