#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxScoreSightseeingPair(vector<int>& values) {
		int result = 0;								// 답으로 출력할 값
		int current_max_value = values[0];			// value 배열에서 가장 큰 원소의 값

		for (int i = 1; i < values.size(); i++) {
			current_max_value--;

			result = max(result, values[i] + current_max_value);		// 새로운 result 계산
			current_max_value = max(current_max_value, values[i]);		// 다음에 result를 계산하기 위해 해당 시점에서 가장 큰 원소의 값을 찾는다
		}

		return result;
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	sol.qwer();
//
//	return 0;
//}