#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Hazel {

	// Main application class of the engine will provide all required functionality to the subclass/executable code. 
	class HAZEL_API Application
	{
	public:
		Application(); 
		virtual ~Application();

		void Run(); 
	private:
		bool m_Running = true;
		std::unique_ptr<Window> m_Window; 
	private:
	};

	// To be defined in CLIENT
	Application* CreateApplication(); 

}
