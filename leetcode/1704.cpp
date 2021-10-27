#include <iostream>
using namespace std;

/*

*/

class Solution {
public:
	bool isVowel(char input) {
		// return true if input is vowel
		if (input=='a' || input == 'e' || input == 'i' || input == 'o' || input == 'u' || input == 'A' || input == 'E' || input == 'I' || input == 'O' || input == 'U') {
			return true;
		}
		return false;
	}

	bool halvesAreAlike(string s) {
		int result = 0;

		int index_front = 0;
		int index_back = s.size()-1;
		while (index_front*2<index_back) {
			if (isVowel(s[index_front])) {
				result++;
			}
			if (isVowel(s[index_back-index_front])) {
				result--;
			}
			index_front++;
		}

		return (result == 0) ? true : false;
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	sol.qwer();
//
//	return 0;
//}