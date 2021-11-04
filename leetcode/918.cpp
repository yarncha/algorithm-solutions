#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxSubarraySumCircular(vector<int>& nums) {
		int total_sum = nums[0];                    // nums 배열 원소들의 총 합
		int subarray_max_sum = nums[0];             // i번째 원소를 마지막 원소로 가지는 부분 수열 중 가장 큰 합
		int max_subarray_max_sum = nums[0];         // 모든 원소에 대한 subarray_max_sum중 가장 큰 값
		int subarray_min_sum = nums[0];             // i번째 원소를 마지막 원소로 가지는 부분 수열 중 가장 작은 합
		int min_subarray_min_sum = nums[0];         // 모든 원소에 대한 subarray_min_sum중 가장 작은 값

		for (int i = 1; i < nums.size(); i++) {
			total_sum += nums[i];

			subarray_max_sum = max(subarray_max_sum + nums[i], nums[i]);
			max_subarray_max_sum = max(max_subarray_max_sum, subarray_max_sum);

			subarray_min_sum = min(subarray_min_sum + nums[i], nums[i]);
			min_subarray_min_sum = min(min_subarray_min_sum, subarray_min_sum);
		}

		int answer;
		if (total_sum == min_subarray_min_sum) {
			// 모든 원소를 다 더한 것이 최소 부분합의 최소와 같을 때는 배열의 원소들이 모두 음수or0이라는 뜻
			// 따라서 그냥 최대 부분합의 최대만 리턴해주면 된다. 따로 circular 신경쓸 필요 없음
			answer = max_subarray_max_sum;
		}
		else {
			// 그런 경우가 아니라면 최대 부분합의 최대(max_subarray_max_sum)와 총 합에서 최소 부분합의 최소(min_subarray_min_sum)를 뺀 값 중 더 큰 것을 answer로 넣어주면 된다.
			// 총 합에서 최소 부분합의 최소(min_subarray_min_sum)를 뺀 값을 따지는 이유는 circular이기 때문. 모든 원소의 합에서 최소 부분합의 최소를 뺀다는 것은 가장 작은 값을 빼서 만든 큰 값이다. 이를 최대 부분합의 최대와 비교해 보면 circular상태도 따지는 것이 된다.
			answer = max(max_subarray_max_sum, total_sum - min_subarray_min_sum);
		}

		return answer;
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	sol.qwer();
//
//	return 0;
//}