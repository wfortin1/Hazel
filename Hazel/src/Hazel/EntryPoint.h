#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication(); 

int main(int argc, char** argv)
{
	Hazel::Application* application = Hazel::CreateApplication(); 
	application->Run(); 
	delete application; 
}

#endif