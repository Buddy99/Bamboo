#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Bamboo
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");				// Colour, Timestamp, Name of the Logger (Core or Client), LogMessage
		s_CoreLogger = spdlog::stdout_color_mt("BAMBOO");
		s_CoreLogger->set_level(spdlog::level::trace);		// Set Log-Level for the CoreLogger
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);	// Set Log-Level for the ClientLogger
	}
}