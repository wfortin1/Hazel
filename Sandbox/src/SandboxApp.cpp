#include <Hazel.h>

class ExampleLayer : public Hazel::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		HZ_INFO("ExampleLayer::Update");
	}

	void OnEvent(Hazel::Event& event) override
	{
		HZ_TRACE("{0}", event);
	}
};

// Sandbox client app
class SandboxApp : public Hazel::Application
{
public: 
	SandboxApp()
	{
		PushLayer(new ExampleLayer());
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