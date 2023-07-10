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
	}

	void OnEvent(Hazel::Event& event) override
	{
	}
};

// Sandbox client app
class SandboxApp : public Hazel::Application
{
public: 
	SandboxApp()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Hazel::ImGuiLayer());
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