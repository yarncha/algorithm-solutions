#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> sumZero(int n) {
		vector<int> res(n);
		for (int i = 0; i < n / 2; i++)
		{
			res[2 * i] = i + 1;
			res[2 * i + 1] = (i + 1) * -1;
		}
		if (n % 2 != 0) {
			res[n - 1] = 0;
		}

		return res;
	}
};

int main(void) {
	Solution sol = Solution();
	vector<int> a = sol.sumZero(6);
	return 0;
}