#pragma once

// This is the entry point of the engine/application. This should be included by the client side application. 
// This includes the main function and simply creates a new application based on the external CreateApplication() function
// Defined in the client side code. Just starts the app which should be implemented by the subclass.

#include "Log.h"
#include "Application.h"

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication(); 

int main(int argc, char** argv)
{
	Hazel::Log::Init(); 
	HZ_CORE_WARN("Initialized Client Log!");
	int a = 5; 
	HZ_INFO("Initialized Engine Log! Var={}", a);

	Hazel::Application* app = Hazel::CreateApplication(); 
	app->Run(); 
	delete app; 
}

#endif