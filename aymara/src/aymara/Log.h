#pragma once

#include <memory.h>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace aymara {

	class AYMARA_API Log
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

#define AYM_CORE_ERROR(...) ::aymara::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AYM_CORE_WARN(...) ::aymara::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AYM_CORE_INFO(...) ::aymara::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AYM_CORE_TRACE(...) ::aymara::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define AYM_ERROR(...) ::aymara::Log::GetClientLogger()->error(__VA_ARGS__)
#define AYM_WARN(...) ::aymara::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AYM_INFO(...) ::aymara::Log::GetClientLogger()->info(__VA_ARGS__)
#define AYM_TRACE(...) ::aymara::Log::GetClientLogger()->trace(__VA_ARGS__)