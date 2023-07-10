#pragma once

#include "Hazel/Layer.h"
#include "Platform/Windows/WindowsWindow.h"

namespace Hazel {

	class HAZEL_API ImGuiLayer : public Layer 
	{
	public:
		ImGuiLayer();
		~ImGuiLayer(); 

		void OnAttach(); 
		void OnDetach(); 
		void OnUpdate();
		void OnEvent(Event& event);
	private:
		float m_Time; 
	};

}