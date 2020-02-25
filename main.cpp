#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <forward_list>
#include <algorithm>
using namespace std;

int main()
{
	std::numeric_limits<int>::epsilon();
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	vector<string> svec{ "123.0","234.4","4323.2" };
	double sum = 0.0;
	for_each(begin(svec), end(svec), [&sum](string& i) {sum += stod(i); });
	cout << sum;
	return 0;
}
