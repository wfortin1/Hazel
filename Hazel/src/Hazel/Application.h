#pragma once

#include "Window.h"
#include "LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace Hazel {

	// Main application class of the engine will provide all required functionality to the subclass/executable code. 
	class HAZEL_API Application
	{
	public:
		Application(); 
		virtual ~Application();

		void Run(); 

		void OnEvent(Event& e); 

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		bool m_Running = true;
		std::unique_ptr<Window> m_Window; 
		LayerStack m_LayerStack; 
	private:
		static Application* s_Instance; 
	};

	// To be defined in CLIENT
	Application* CreateApplication(); 

}
