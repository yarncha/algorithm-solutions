#include <iostream>
#include <string>
using namespace std;

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sorting the Sentence.
Memory Usage: 6.3 MB, less than 71.45% of C++ online submissions for Sorting the Sentence.
*/

class Solution {
public:
	string sortSentence(string s) {
		string arr[10];

		string a_word = "";
		for (int i = 0; i < s.size(); i++)
		{
			char cur_char = s.at(i);
			if (cur_char >= '1' && cur_char <= '9') {
				arr[cur_char - 48] = a_word;
				a_word = "";
			}
			else if ((cur_char >= 'a' && cur_char <= 'z') || (cur_char >= 'A' && cur_char <= 'Z')) {
				a_word.push_back(cur_char);
			}
		}

		string result = "";
		int index = 1;
		while (arr[index] != "")
		{
			result += arr[index];
			index++;

			if (arr[index] != "") {
				result += " ";
			}
		}

		return result;
	}
};

int main(void) {
	Solution sol = Solution();

	sol.sortSentence("Myself2 Me1 I4 and3");

	return 0;
}