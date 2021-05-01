#include "Timing.h"

namespace Bamboo
{
	void Timing::Init()
	{
		start = std::chrono::system_clock::now();	// Set Starttime
		SetFixedFrameTime(1 / 60.f);				// Set Simulation Framerate
		SetRenderFrameTime(1 / 60.f);				// Set Render Framerate
	}

	double Timing::GetTimeSinceStartup()
	{
		return std::chrono::duration<double>(std::chrono::system_clock::now() - start).count();
	}

	void Timing::SetFixedFrameTime(double frameTime)
	{
		FixedFrameTime = frameTime;
	}

	double Timing::GetFixedFrameTime()
	{
		return FixedFrameTime;
	}

	void Timing::SetRenderFrameTime(double frameTime)
	{
		RenderFrameTime = frameTime;
	}

	double Timing::GetRenderFrameTime()
	{
		return RenderFrameTime;
	}

	void Timing::SetDeltaTime(double deltaTime)
	{
		DeltaTime = deltaTime;
	}

	double Timing::GetDeltaTime()
	{
		return DeltaTime;
	}

}