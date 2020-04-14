#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <queue>
#include <list>
#include <forward_list>
#include <stack>
#include "Sort.h"
#include "Node.h"
using namespace std;
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
template <class ForwardIt>
void quicksort(ForwardIt first, ForwardIt last)
{
    if (first == last) return;
    auto pivot = *std::next(first, std::distance(first, last) >> 1);
    ForwardIt middle1 = std::partition(first, last,
        [&pivot](const auto& em) { return em < pivot; });
    ForwardIt middle2 = std::partition(middle1, last,
        [&pivot](const auto& em) { return !(pivot < em); });
    quicksort(first, middle1);
    quicksort(middle2, last);
}
int main()
{
#if (defined _MSC_VER) && (defined _DEBUG) 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define DBG_NEW new
#endif
    Node n;
    cout << n;

    /*
	vector<int> ivec{ 12, 11, 2,3,4,5,6,7,8,9 };
    Sort::QuickSort(begin(ivec), end(ivec),std::less<int>());
	for (auto i : ivec) cout << i << " ";
    */
	return 0;
}
