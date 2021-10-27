#include <iostream>
using namespace std;

class Solution {
public:
	int answer[38] = { 0, };
	int tribonacci(int n) {
		answer[0] = 0;
		answer[1] = 1;
		answer[2] = 1;

		int current = 3;
		while (current <= n)
		{
			if (answer[current] == 0) {
				answer[current] = answer[current - 1] + answer[current - 2] + answer[current - 3];
			}
			current++;
		}

		return answer[n];
	}
};

int main(void) {
	Solution sol = Solution();

	cout << sol.tribonacci(37);

	return 0;
}