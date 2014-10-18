#ifndef TEMERE_UTILITY_SINGLETON_DESTROYER_H
#define TEMERE_UTILITY_SINGLETON_DESTROYER_H

#include "macro.h"

namespace Temere
{
	namespace Utility
	{
		template<class T>
		class SingletonDestroyer
		{
		public:
			TEMERE_DYNAMIC_LIBRARY_PREFIX SingletonDestroyer();
			TEMERE_DYNAMIC_LIBRARY_PREFIX virtual ~SingletonDestroyer();
			TEMERE_DYNAMIC_LIBRARY_PREFIX inline void setSingleton(T* pSingleton) { mpSingleton = pSingleton; }

		private:
			TEMERE_DYNAMIC_LIBRARY_PREFIX SingletonDestroyer(const SingletonDestroyer& ref);
			TEMERE_DYNAMIC_LIBRARY_PREFIX const SingletonDestroyer &operator=(const SingletonDestroyer &ref);

			T* mpSingleton;
		};

		template<class T>
		SingletonDestroyer<T>::SingletonDestroyer()
		{
			mpSingleton = 0;
		}

		template<class T>
		SingletonDestroyer<T>::~SingletonDestroyer()
		{
			TEMERE_SAFE_DELETE(mpSingleton)
		}

		template<class T>
		SingletonDestroyer<T>::SingletonDestroyer(const SingletonDestroyer<T>& ref)
		{
			TEMERE_UREF(ref)
		}

		template<class T>
		const SingletonDestroyer<T>& SingletonDestroyer<T>::operator=(const SingletonDestroyer<T>& ref)
		{
			TEMERE_UREF(ref)
			return *this;
		}
	}
}

#endif