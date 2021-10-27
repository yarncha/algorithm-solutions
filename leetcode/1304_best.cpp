#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> sumZero(int n) {
		vector<int> res(n);
		int sum = 0;
		for (int i = 0; i < n - 1; i++)
		{
			res[i] = i;
			sum = sum + i;
		}
		res[n - 1] = sum * (-1);

		return res;
	}
};

int main(void) {
	Solution sol = Solution();
	vector<int> a = sol.sumZero(6);
	return 0;
}