#include "timer.h"
#include <Windows.h>

using namespace Temere::Utility;

Timer::Timer()
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&mFrequency);
	QueryPerformanceCounter((LARGE_INTEGER*)&mStartCount);
	mEndCount = 0;
	mTicksPerUnit = 1.0 / mFrequency;
}

Timer::~Timer()
{
}

Timer::Timer(const Timer& ref)
{
	TEMERE_UREF(ref)
}

const Timer& Timer::operator=(const Timer& ref)
{
	TEMERE_UREF(ref)
	return *this;
}

double Timer::getElapsedTime()
{
	mEndCount = mStartCount;
	QueryPerformanceCounter((LARGE_INTEGER*)&mStartCount);

	return (mStartCount - mEndCount) * mTicksPerUnit;
}