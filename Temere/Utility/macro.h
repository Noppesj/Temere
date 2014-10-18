#ifndef TEMERE_UTILITY_MACRO_H
#define TEMERE_UTILITY_MACRO_H

#define TEMERE_OS_WIN
#define TEMERE_OS_UNIX
#define TEMERE_OS_IOS

#ifdef TEMERE_OS_WIN
	#define TEMERE_DYNAMIC_LIBRARY_PREFIX __declspec(dllexport)
#elif defined TEMERE_OS_UNIX
	#define TEMERE_DYNAMIC_LIBRARY_PREFIX
#elif defined TEMERE_OS_IOS
	#define TEMERE_DYNAMIC_LIBRARY_PREFIX
#endif

#define TEMERE_UREF(x) ((void)x);
#define TEMERE_NEW new
#define TEMERE_SAFE_DELETE(x) if(x){delete x; x = 0;}
#define TEMERE_SAFE_DELETE_ARRAY(x) if(x){delete [] x; x = 0;}

#endif