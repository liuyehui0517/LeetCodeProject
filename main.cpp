#include <iostream>
#include <vector>
#include <string>
#include "Tree.h"

using namespace std;
#if (defined _MSC_VER) && (defined _DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <cstdlib> 
#include <crtdbg.h>
#endif

int main()
{
#if (defined _MSC_VER) && (defined _DEBUG) 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define DBG_NEW new
#endif
	using tree::BSTree;
	BSTree root(3);
	cout << root.size() << root.height();
	return 0;
}
