#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h" // We add this so that we can use custom ostream operator

namespace Hazel {

	// Class used for logging. To access a log use Log::Get<name>Logger(); 
	class HAZEL_API Log
	{
	public:
		static void Init(); 

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger; 
		static std::shared_ptr<spdlog::logger> s_ClientLogger; 
	};
}

// We define some macros so that we can avoid calling static object member methods all throughout our code.
// Also allows us to easily switch out logging libraries if required.

// Core Log Macros 
#define HZ_CORE_TRACE(...)     ::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)      ::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)      ::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)     ::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_CRITICAL(...)  ::Hazel::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log Macros
#define HZ_TRACE(...)	       ::Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)	       ::Hazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)	       ::Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...)	       ::Hazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_CRITICAL(...)       ::Hazel::Log::GetClientLogger()->critical(__VA_ARGS__)
