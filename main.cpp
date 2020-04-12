#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <forward_list>
#include <stack>

#if (defined _MSC_VER) && (defined _DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <cstdlib> 
#include <crtdbg.h>
#endif

#ifdef __cpp_lib_experimental_propagate_const
#include <propagate_const>
#else
#include "propagate_const.h"
using std::experimental::propagate_const;
#endif

int main()
{
#if (defined _MSC_VER) && (defined _DEBUG) 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define DBG_NEW new
#endif
	
	return 0;
}
