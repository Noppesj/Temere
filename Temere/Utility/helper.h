#ifndef SV11_UTILITY_HELPER_H
#define SV11_UTILITY_HELPER_H
#include "macro.h"
#include "singletondestroyer.h"
#include <atomic>
#include <mutex>
#include <vector>
#include <string>
#include <unordered_map>

namespace Temere
{
	namespace Utility
	{
		class Helper
		{
		public:
			TEMERE_DYNAMIC_LIBRARY_PREFIX static Helper* getInstance();
			TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~Helper();

			TEMERE_DYNAMIC_LIBRARY_PREFIX int characterCount(const std::string &sSource, char c);
			TEMERE_DYNAMIC_LIBRARY_PREFIX int characterCount(const std::string &sSource, char c1, char c2);
			TEMERE_DYNAMIC_LIBRARY_PREFIX std::vector<int> characterCountLength(const std::string &sSource, char c);
			TEMERE_DYNAMIC_LIBRARY_PREFIX std::vector<int> characterCountLength(const std::string &sSource, char c1, char c2);
			TEMERE_DYNAMIC_LIBRARY_PREFIX int parseInt(std::string &sSource);
			TEMERE_DYNAMIC_LIBRARY_PREFIX float parseFloat(std::string &sSource);
			TEMERE_DYNAMIC_LIBRARY_PREFIX void parseValues(const std::string &sSource, std::vector<float> &outVector);
			TEMERE_DYNAMIC_LIBRARY_PREFIX void parseValues(const std::string &sSource, std::vector<int> &outVector);
		private:
			TEMERE_DYNAMIC_LIBRARY_PREFIX Helper();
			TEMERE_DYNAMIC_LIBRARY_PREFIX Helper(const Helper& ref);
			TEMERE_DYNAMIC_LIBRARY_PREFIX const Helper& operator=(const Helper& ref);

			static std::atomic<Helper*> mpInstance;
			static Temere::Utility::SingletonDestroyer<Helper> mDestroyer;
			static std::mutex mThreadLock;
			std::unordered_map<char, bool> mValidIntValue;
			std::unordered_map<char, bool> mValidFloatValue;
		};
	}
}

#endif