#include <iostream>
#include <vector>
#include <string>
#include "Tree.h"
using namespace std;
#if (defined _MSC_VER) && (defined _DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <cstdlib> 
#include <crtdbg.h>
#endif // defined (_MSC_VER && _DEBUG)

int main()
{
#if (defined _MSC_VER) && (defined _DEBUG) 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define DBG_NEW new
#endif // defined (_MSC_VER && _DEBUG)
	tree::RBTree root(0, "ZERO");
	root.set(1, "ONE");
	root.set(3, "ONE");
	root.set(4, "ONE");
	root.set(2, "ONE");
	root.set(-1, "ONE");
	return 0;
}
