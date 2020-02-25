#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <random>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> data;
	int i;
	for (i = 0; i != nums.size(); ++i) {
		if (data.find(target - nums[i]) != cend(data)) break;
		else data.insert(make_pair(nums[i],i));
	}
	if (i < nums.size())
		return vector<int>{data[target - nums[i]], i};
	else
		return vector<int>();
}

int main()
{
	vector<int> dataSource = { 2,11,14,99,4 };
	int target = 16;
	auto answer = twoSum(dataSource, target);
	for (auto i : answer) cout << i << "|";
	return 0;
}
