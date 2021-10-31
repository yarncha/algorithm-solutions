#include <iostream>
#include <vector>
using namespace std;

/*
Runtime: 52 ms, faster than 91.76% of C++ online submissions for Jump Game.
Memory Usage: 48.4 MB, less than 18.90% of C++ online submissions for Jump Game.
*/

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int size_of_array = nums.size();
		int current_index = 0;					// 0부터 시작해서 현재 위치한 index;
		int index_can_reach = 0;				// 현재 위치한 index에서 최대로 갈 수 있는 거리

		while ((current_index < size_of_array) && (current_index <= index_can_reach))
		{
			// index_can_reach를 계속 늘려보면서 current_index에서 최대한 갈 수 있는 거리를 찾아 본다.
			index_can_reach = max(index_can_reach, current_index + nums[current_index]);
			current_index++;
		}

		return current_index == size_of_array;		// 현재 위치로 true/false 따지기
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	sol.qwer();
//
//	return 0;
//}