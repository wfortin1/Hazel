#include "hzpch.h"
#include "Application.h"

#include "Hazel/Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>

namespace Hazel {

	#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create()); 
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent)); 
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClosed));
		
		for (auto layer = m_LayerStack.end(); layer != m_LayerStack.begin();)
		{
			(*--layer)->OnEvent(e); 
			if (e.Handled())
				break;
		}
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT); 
			m_Window->OnUpdate(); 

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate(); 
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}



	bool Application::OnWindowClosed(WindowCloseEvent& e)
	{
		m_Running = false; 
		return true; 
	}

}