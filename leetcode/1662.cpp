#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Runtime: 8 ms
Memory Usage: 11.6 MB
*/

class Solution {
public:
	bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
		string total_word1 = "";
		for (int i = 0; i < word1.size(); i++)
		{
			total_word1 += word1[i];
		}

		string total_word2 = "";
		for (int j = 0; j < word2.size(); j++)
		{
			total_word2 += word2[j];
		}

		if (total_word1 == total_word2) {
			return true;
		}
		return false;
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	sol.qwer();
//
//	return 0;
//}