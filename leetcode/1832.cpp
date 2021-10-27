#include <iostream>
using namespace std;

/*
Runtime: 4 ms, faster than 71.93% of C++ online submissions for Check if the Sentence Is Pangram.
Memory Usage: 6.5 MB, less than 74.91% of C++ online submissions for Check if the Sentence Is Pangram.
*/

class Solution {
public:
	int alpabet_arr[26];

	bool checkIfPangram(string sentence) {
		for (int i = 0; i < sentence.size(); i++)
		{
			int cur_num = sentence[i] - 97;
			alpabet_arr[cur_num]++;
		}

		for (int j = 0; j < 26; j++)
		{
			if (alpabet_arr[j] == 0) {
				return false;
			}
		}
		return true;
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	sol.qwer();
//
//	return 0;
//}