#include <iostream>
using namespace std;

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Prefix of Word.
Memory Usage: 6.2 MB, less than 33.08% of C++ online submissions for Reverse Prefix of Word.
*/

class Solution {
public:
	string reversePrefix(string word, char ch) {
		/*
		word : given input string
		ch : reverse string from index 0 to index of ch's first occurence
		*/
		string result = word;       // result string
		int index_of_ch = -1;       // index of first occurence

		// 1. find ch in word
		for (int i = 0; i < word.size(); i++)
		{
			if (word[i] == ch) {
				index_of_ch = i;
				break;
			}
		}

		// 2. if ch is not -1, there is ch in word. so reverse it from index 0 to index index_of_ch
		if (ch != -1) {
			int temp_index = 0;
			while (temp_index < index_of_ch - temp_index)
			{
				char temp_char = result[temp_index];
				result[temp_index] = result[index_of_ch - temp_index];
				result[index_of_ch - temp_index] = temp_char;
				temp_index++;
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