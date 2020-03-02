#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC
#include <cstdlib> 
#include <crtdbg.h>
#ifdef _DEBUG
	#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
	#define DBG_NEW new
#endif
#endif

#ifdef __GNUC__
#pragma GCC optimize(2)
#pragma G++ optimize(2) 
#endif

int main()
{
	#ifdef _MSC_VER
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	#endif
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	return 0;
}
