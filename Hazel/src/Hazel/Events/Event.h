#pragma once 

#include "Hazel/Core.h"

namespace Hazel {

	// Events in hazel are currently blocking, meaning when an event occurs
	// it immediately gets dispatched and dealt with right away.

	// Enum to assign an id to each event 
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender, 
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// Event category types to filter by certain events 
	enum EventCategory
	{
		None = 0, 
		EventCategoryApplication  = BIT(0),
		EventCategoryInput		  = BIT(1),
		EventCategoryKeyboard	  = BIT(2),
		EventCategoryMouse		  = BIT(3),
		EventCategoryMouseButton  = BIT(4)
	};

	// These methods are created as defines so that we don't have to explicitly declare these in each event 
	#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								   virtual EventType GetEventType() const override { return GetStaticType(); }\
								   virtual const char* GetName()  const override { return #type; }
	
	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class HAZEL_API Event
	{
		friend class EventDispatcher; // Friend classes can access protected variables?
	public:
		virtual EventType GetEventType() const = 0; 
		virtual const char* GetName() const = 0; 
		virtual int GetCategoryFlags() const = 0; 
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category; 
		}
	protected:
		bool m_Handled = false; 
	};

	// Used to dispatch events based on their type.
	// If we receive an event, we receive an event reference.
	// We can create an EventDispatcher with the event reference that we have received.
	// We then call the dispatch multiple times with different EventFn.
	// Write a function that takes in an event type and returns a boolean (Handled)
	// If the function given matches the event type it will run that function
	// From there you can either dispatch this function somewhere else or have it be handled (return true).
	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>; 
	public:
		EventDispatcher(Event& event)
			: m_Event(event) {}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true; 
			}
			return false; 
		}
	private:
		Event& m_Event; 
	};

	// Used for logging library so that we can log events easily
	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString(); 
	}
	 
}