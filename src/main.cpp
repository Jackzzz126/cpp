#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool small(int a, int b) {
	return a > b;
};
int main()
{
	vector<int> nums = {1, 3, 5, 9, 2, 4};
	for(auto i = nums.begin(); i != nums.end(); i++) {
		cout << *i << endl;
	}
	cout << endl;
	sort(nums.begin(), nums.end(), small);
	for(auto i = nums.begin(); i != nums.end(); i++) {
		cout << *i << endl;
	}
	return 0;
}
