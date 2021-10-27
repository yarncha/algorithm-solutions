#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
		int result = 0;

		int ruleIndex;
		if (ruleKey == "type") {
			ruleIndex = 0;
		}
		else if (ruleKey == "color") {
			ruleIndex = 1;
		}
		else if (ruleKey == "name") {
			ruleIndex = 2;
		}

		int n = items.size();
		for (int i = 0; i < n; i++)
		{
			if (items[i][ruleIndex] == ruleValue) {
				result++;
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