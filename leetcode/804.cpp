#include <iostream>
#include <vector>
using namespace std;

/* Runtime: 4 ms, faster than 67.19% of C++ online submissions for Unique Morse Code Words.
Memory Usage: 8.3 MB, less than 98.42% of C++ online submissions for Unique Morse Code Words. */

class Solution {
public:
	string morse_codes[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
	string appeared_words[100];
	int size_of_appeared_words = 0;
	int uniqueMorseRepresentations(vector<string>& words) {
		for (int i = 0; i < words.size(); i++)
		{
			// 먼저 각 단어로 모스코드 만들어봄
			string morse_code_word = "";
			for (int j = 0; j < words[i].size(); j++)
			{
				morse_code_word += morse_codes[words[i][j] - 97];
			}

			// appeard_words를 찾아보고 없을 경우 넣어줌
			bool is_appeared = false;
			for (int k = 0; k < size_of_appeared_words; k++)
			{
				if (appeared_words[k] == morse_code_word) {
					is_appeared = true;
					break;
				}
			}
			if (!is_appeared) {
				appeared_words[size_of_appeared_words++] = morse_code_word;
			}
		}

		return size_of_appeared_words;
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	sol.qwer();
//
//	return 0;
//}