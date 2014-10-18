#include "animationlogic.h"

using namespace Temere::Logic;

AnimationLogic::AnimationLogic()
{
	mStartIndex = 0;
	mEndIndex = 0;
	mCurrentIndex = 0;
}

AnimationLogic::AnimationLogic(unsigned int startIndex, unsigned int endIndex)
{
	mStartIndex = startIndex;
	mEndIndex = endIndex;
	mCurrentIndex = startIndex;
}

AnimationLogic::~AnimationLogic()
{
}

unsigned int AnimationLogic::getNextIndex()
{
	mCurrentIndex++;

	if(mCurrentIndex > mEndIndex)
	{
		mCurrentIndex = mStartIndex;
	}
	return mCurrentIndex;
}

unsigned int AnimationLogic::getPrevIndex()
{
	mCurrentIndex--;

	if(mCurrentIndex < mStartIndex)
	{
		mCurrentIndex = mStartIndex;
	}
	return mCurrentIndex;
}

void AnimationLogic::reset()
{
	mCurrentIndex = mStartIndex;
}

unsigned int AnimationLogic::getStartIndex()
{
	return mStartIndex;
}