#include <iostream>
#include <vector>
using namespace std;

/*
Runtime: 12 ms, faster than 47.14% of C++ online submissions for Trapping Rain Water.
Memory Usage: 15.7 MB, less than 61.60% of C++ online submissions for Trapping Rain Water.
*/

/*
접근 방법

left, right의 두 개의 포인터를 두고, 각각 끝에서부터 가운데로 이동한다
height[right], height[left]를 비교해서 더 작은 쪽의 포인터를 가운데로 이동시키면서 max_left(right)와 현재 높이를 계산하고, 최대값을 max_left(right)에 저장한다.
max보다 작은 값이 나올 때에는 그 지점은 물이 가둬지는 곳이므로, result에 더해 주었다.
*/

class Solution {
public:
	int trap(vector<int>& height) {
		int left = 0, right = height.size() - 1;		// two pointer를 둠
		int max_left = height[left], max_right = height[right];

		int result = 0;
		while (left < right)
		{
			if (max_left < height[left]) {
				max_left = height[left];
			}
			else {
				result += max_left - height[left];
			}

			if (max_right < height[right]) {
				max_right = height[right];
			}
			else {
				result += max_right - height[right];
			}

			if (height[left] <= height[right]) {
				left++;
			}
			else {
				right--;
			}
		}

		return result;
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	cout << sol.qwer();
//
//	return 0;
//}