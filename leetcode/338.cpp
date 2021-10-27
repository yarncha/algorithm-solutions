#include <iostream>
#include <vector>
using namespace std;

/*

Runtime: 4 ms, faster than 91.09% of C++ online submissions for Counting Bits.
Memory Usage: 8.5 MB, less than 29.80% of C++ online submissions for Counting Bits.

*/

class Solution {
public:
	vector<int> countBits(int n) {
		vector<int> num_of_1s;

		num_of_1s.push_back(0);
		if (n == 0) {
			return num_of_1s;
		}
		num_of_1s.push_back(1);

		for (int i = 2; i <= n; i++)
		{
			if (i % 2 == 0) {
				num_of_1s.push_back(num_of_1s[i / 2]);
			}
			else {
				num_of_1s.push_back(num_of_1s[i - 1] + 1);
			}
		}

		return num_of_1s;
	}
};

int main(void) {
	Solution sol = Solution();

	sol.countBits(2);

	return 0;
}