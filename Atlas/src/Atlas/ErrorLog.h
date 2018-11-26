#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Atlas
{
	class ATLAS_API Log 
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

//CORE LOGS MACROS

#define AT_CORE_TRACE(...)		::Atlas::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AT_CORE_INFO(...)		::Atlas::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AT_CORE_WARN(...)		::Atlas::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AT_CORE_ERROR(...)		::Atlas::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AT_CORE_FATAL(...)		::Atlas::Log::GetCoreLogger()->critical(__VA_ARGS__)

//CLIENT LOGS MACROS

#define AT_TRACE(...)			::Atlas::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AT_INFO(...)			::Atlas::Log::GetClientLogger()->info(__VA_ARGS__)
#define AT_WARN(...)			::Atlas::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AT_ERROR(...)			::Atlas::Log::GetClientLogger()->error(__VA_ARGS__)
#define AT_FATAL(...)			::Atlas::Log::GetClientLogger()->critical(__VA_ARGS__)