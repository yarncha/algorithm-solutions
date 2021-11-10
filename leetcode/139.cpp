#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Runtime: 4 ms, faster than 91.59% of C++ online submissions for Word Break.
Memory Usage: 7.6 MB, less than 89.77% of C++ online submissions for Word Break.
*/

// Time Limit Exceeded Answer
//class Solution {
//public:
//	vector<int> movement_allowed[300];      // i번째 글자에서 이동 가능한 거리를 출력
//
//	bool IsVaild(int index, int string_size) {
//		if (index== string_size) {
//			return true;
//		}
//		if (movement_allowed[index].size()==0) {
//			return false;
//		}
//
//		for (int i = 0; i < movement_allowed[index].size(); i++)
//		{
//			if (IsVaild(index+movement_allowed[index][i], string_size)) {
//				return true;
//			}
//		}
//
//		return false;
//	}
//
//	bool wordBreak(string s, vector<string>& wordDict) {
//		// 1. 먼저 wordDict에서 모든 단어들에 대해 s에서 존재하는 것들을 다 find하면서 찾는다.
//		for (int i = 0; i < wordDict.size(); i++)
//		{
//			int word_size = wordDict[i].size();
//
//			int index_to_find = 0;
//			int index_of_found_word = s.find(wordDict[i]);
//			while (index_of_found_word != string::npos)
//			{
//				movement_allowed[index_of_found_word].push_back(word_size);
//				index_to_find = index_of_found_word + 1;
//				if (index_to_find < s.size()) {
//					index_of_found_word = s.find(wordDict[i], index_to_find);
//				}
//				else {
//					break;
//				}				
//			}
//		}
//
//		// 2. 재귀적으로 이동해보며 가능한 방법을 찾는다.
//		return IsVaild(0, s.size());
//	}
//};

class Solution {
public:
	int dp[301];		// i인덱스부터 쭉 매치되는 글자가 있는지 여부를 저장할 배열

	bool wordBreak(string s, vector<string>& wordDict) {
		int size_of_input_string = s.size();		// wordDict 배열의 크기
		dp[size_of_input_string] = true;			// 시작을 true로 초기화
		for (int i = size_of_input_string - 1; i >= 0; i--)
		{
			// s를 한글자씩 뒤로 읽어가면서 매칭되는 word가 있는지 살핌
			for (int j = 0; j < wordDict.size(); j++)
			{
				string current_word = wordDict[j];
				if (s.find(current_word, i) == i && dp[i + current_word.size()]) {
					dp[i] = true;
				}
			}
		}

		return dp[0];
	}
};

int main(void) {
	Solution sol = Solution();

	string s = "danana";
	vector<string> input_vector = { "dan","ana" };
	cout << sol.wordBreak(s, input_vector);

	return 0;
}