#include "helper.h"
#include <algorithm>
using namespace Temere::Utility;

std::atomic<Helper*> Helper::mpInstance = 0;
SingletonDestroyer<Helper> Helper::mDestroyer;
std::mutex Helper::mThreadLock;

Helper* Helper::getInstance()
{
	mThreadLock.lock();
	if(!(Helper*)mpInstance)
	{
		mpInstance = new Helper();
		mDestroyer.setSingleton(mpInstance);
	}
	mThreadLock.unlock();
	return mpInstance;
}

Helper::~Helper()
{
}

int Helper::characterCount(const std::string &sSource, char c)
{
	int iCount = 0;
	for(unsigned int n = 0; n < sSource.length(); ++n)
	{
		if(sSource[n] == c)
		{
			++iCount;
		}
	}
	return iCount;
}

int Helper::characterCount(const std::string &sSource, char c1, char c2)
{
	int iCount = 0;
	for(unsigned int n = 0; n < sSource.length(); ++n)
	{
		if(sSource[n] == c1 || sSource[n] == c2)
		{
			++iCount;
		}
	}
	return iCount;
}

std::vector<int> Helper::characterCountLength(const std::string &sSource, char c)
{
	std::vector<int> lengthVector;
	for(unsigned int n = 0; n < sSource.length(); ++n)
	{
		if(sSource[n] == c)
		{
			lengthVector.push_back(n);
		}
	}
	return lengthVector;
}

std::vector<int> Helper::characterCountLength(const std::string &sSource, char c1, char c2)
{
	std::vector<int> lengthVector;
	for(unsigned int n = 0; n < sSource.length(); ++n)
	{
		if(sSource[n] == c1 || sSource[n] == c2)
		{
			lengthVector.push_back(n);
		}
	}
	return lengthVector;
}

int Helper::parseInt(std::string &sSource)
{
	bool bNegative = false;
	if(sSource.length() > 0 && sSource[0] == '-')
	{
		bNegative = true;
		std::remove(sSource.begin(), sSource.end(), '-');
	}
	int iValue = 0;
	for(unsigned int n = 0; n < sSource.length(); ++n)
	{
		iValue += (sSource[n] - 48) * (int)pow(10, sSource.length() - 1 - n);
	}
	return bNegative ? -1 * iValue : iValue;
}

float Helper::parseFloat(std::string &sSource)
{
	bool bNegative = false;
	if(sSource.length() > 0 && sSource[0] == '-')
	{
		bNegative = true;
		std::remove(sSource.begin(), sSource.end(), '-');
	}
	float fValue = 0.0f;
	std::vector<int> lengthVector = characterCountLength(sSource, '.', ',');
	if(lengthVector.size() == 0)
	{
		for(unsigned int n = 0; n < sSource.length(); ++n)
		{
			fValue += (float)((sSource[n] - 48) * pow(10, sSource.length() - 1 - n));
		}
	}
	else if(lengthVector.size() == 1)
	{
		std::string sFirstPart = sSource.substr(0, lengthVector[0]);
		for(unsigned int n = 0; n < sFirstPart.length(); ++n)
		{
			fValue += (float)((sFirstPart[n] - 48) * pow(10, sFirstPart.length() - 1 - n));
		}

		std::string sSecondPart = sSource.substr(lengthVector[0] + 1);
		for(unsigned int n = 0; n < sSecondPart.length(); ++n)
		{
			fValue += (float)(sSecondPart[n] - 48) / (float)pow(10, n + 1);
		}
	}
	return bNegative ? -1.0f * fValue : fValue;
}

void Helper::parseValues(const std::string &sSource, std::vector<float> &outVector)
{
	outVector.clear();
	std::string sValue;
	for (unsigned int n = 0; n < sSource.length(); ++n)
	{
		if (mValidFloatValue.count(sSource[n]) != 0)
		{
			sValue.append(1, sSource[n]);
			//sValue += sSource[n];
		}
		else if(sValue.length() > 0)
		{
			outVector.push_back(parseFloat(sValue));
			sValue.clear();
		}
	}
	if(sValue.length() > 0)
	{
		outVector.push_back(parseFloat(sValue));
		sValue.clear();
	}
}

void Helper::parseValues(const std::string &sSource, std::vector<int> &outVector)
{
	outVector.clear();
	std::string sValue;
	for (unsigned int n = 0; n < sSource.length(); ++n)
	{
		if (mValidIntValue.count(sSource[n]) != 0)
		{
			sValue.append(1, sSource[n]);
		}
		else if(sValue.length() > 0)
		{
			outVector.push_back(parseInt(sValue));
			sValue.clear();
		}
	}
	if(sValue.length() > 0)
	{
		outVector.push_back(parseInt(sValue));
		sValue.clear();
	}
}

Helper::Helper() : mValidIntValue(), mValidFloatValue()
{
	mValidIntValue.emplace('-', true);
	mValidIntValue.emplace('0', true);
	mValidIntValue.emplace('1', true);
	mValidIntValue.emplace('2', true);
	mValidIntValue.emplace('3', true);
	mValidIntValue.emplace('4', true);
	mValidIntValue.emplace('5', true);
	mValidIntValue.emplace('6', true);
	mValidIntValue.emplace('7', true);
	mValidIntValue.emplace('8', true);
	mValidIntValue.emplace('9', true);

	mValidFloatValue.emplace('-', true);
	mValidFloatValue.emplace('0', true);
	mValidFloatValue.emplace('1', true);
	mValidFloatValue.emplace('2', true);
	mValidFloatValue.emplace('3', true);
	mValidFloatValue.emplace('4', true);
	mValidFloatValue.emplace('5', true);
	mValidFloatValue.emplace('6', true);
	mValidFloatValue.emplace('7', true);
	mValidFloatValue.emplace('8', true);
	mValidFloatValue.emplace('9', true);
	mValidFloatValue.emplace('.', true);
	mValidFloatValue.emplace(',', true);
}

Helper::Helper(const Helper& ref)
{
	TEMERE_UREF(ref)
}

const Helper& Helper::operator=(const Helper& ref)
{
	TEMERE_UREF(ref)
	return *this;
}