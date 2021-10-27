#include <iostream>
using namespace std;



class Solution {
public:
	string truncateSentence(string s, int k) {
		int cur_space = 0;
		string result = "";

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ') {
				cur_space++;
				if (cur_space < k) {
					result.push_back(s[i]);
				}
				else {
					break;
				}
			}
			else {
				result.push_back(s[i]);
			}
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