#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

// Abstraction Layer (The game calls my logger functions which then call the logger [the game can't call the logger directly])
// If I want to change the logger, I only have to change my logger functions

namespace Bamboo 
{
	class BAMBOO_API Log
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

// Core log macros
#define BM_CORE_TRACE(...)  ::Bamboo::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BM_CORE_INFO(...)   ::Bamboo::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BM_CORE_WARN(...)   ::Bamboo::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BM_CORE_ERROR(...)  ::Bamboo::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BM_CORE_FATAL(...)  ::Bamboo::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define BM_TRACE(...)       ::Bamboo::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BM_INFO(...)        ::Bamboo::Log::GetClientLogger()->info(__VA_ARGS__)
#define BM_WARN(...)        ::Bamboo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BM_ERROR(...)       ::Bamboo::Log::GetClientLogger()->error(__VA_ARGS__)
#define BM_FATAL(...)       ::Bamboo::Log::GetClientLogger()->fatal(__VA_ARGS__)