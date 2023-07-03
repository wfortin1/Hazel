#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Hazel {

	// Main application class of the engine will provide all required functionality to the subclass/executable code. 
	class HAZEL_API Application
	{
	public:
		Application(); 
		virtual ~Application();

		void Run(); 
	private:
	};

	// To be defined in CLIENT
	Application* CreateApplication(); 

}
