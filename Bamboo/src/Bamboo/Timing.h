#pragma once

#include "Core.h"
#include <chrono>

namespace Bamboo
{
	class BAMBOO_API Timing
	{
	public:
		static void Init();
		static double GetTimeSinceStartup();

		static void SetFixedFrameTime(double frameTime);
		static double GetFixedFrameTime();

		static void SetRenderFrameTime(double frameTime);
		static double GetRenderFrameTime();

		static void SetDeltaTime(double deltaTime);
		static double GetDeltaTime();

	private:
		inline static std::chrono::system_clock::time_point start;
		inline static double FixedFrameTime;
		inline static double RenderFrameTime;
		inline static double DeltaTime;
	};
}