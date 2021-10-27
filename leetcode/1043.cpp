#include <iostream>
#include <vector>
using namespace std;

/*
Runtime: 8 ms, faster than 97.84% of C++ online submissions for Partition Array for Maximum Sum.
Memory Usage: 8.3 MB, less than 93.53% of C++ online submissions for Partition Array for Maximum Sum.
*/

class Solution {
public:
	int maxSumAfterPartitioning(vector<int>& arr, int k) {
		int maximum_sum[501];      // i번째에서의 최대 합을 저장할 배열

		// 0번째에서는 그냥 0번째 원소와 같으므로 저장해 두고,
		int max_value = arr[0];
		maximum_sum[0] = arr[0];

		// 1번째부터 k-1번째까지는 모두 한 subarray로 묶을 수 있으므로 이 중 가장 큰 원소*개수를 계산한 값을 maximum_sum에 넣어준다.
		for (int i = 1; i < k; i++)
		{
			if (max_value < arr[i]) {
				max_value = arr[i];
			}
			maximum_sum[i] = max_value * (i + 1);
		}

		// k번째 원소부터는 계산을 다르게 해야 함
		for (int j = k; j < arr.size(); j++)
		{
			// 일단 j-1번째 값에 현재 값을 더해준 걸 먼저 값으로 넣어줌
			maximum_sum[j] = maximum_sum[j - 1] + arr[j];
			max_value = arr[j];

			// 그 뒤 이전 값들을 보며 현재 값보다 커질 수 있는 것들이 있는지 살핌
			for (int m = j - 1; m >= j - k + 1; m--)
			{
				if (max_value < arr[m]) {
					max_value = arr[m];
				}

				int temp_val = maximum_sum[m - 1] + max_value * (j - m + 1);
				if (maximum_sum[j] < temp_val) {
					maximum_sum[j] = temp_val;
				}
			}
		}

		// 마지막으로 maximum_sum[arr.size() - 1] return
		return maximum_sum[arr.size() - 1];
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	sol.qwer();
//
//	return 0;
//}