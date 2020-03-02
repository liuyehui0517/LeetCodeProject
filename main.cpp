#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define _CRTDBG_MAP_ALLOC
#include <cstdlib> 
#include <crtdbg.h>
#ifdef _DEBUG
	#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
	#define DBG_NEW new
#endif

#ifdef __GNUC__
#pragma GCC optimize(2)
#pragma G++ optimize(2) 
#endif

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	return 0;
}
