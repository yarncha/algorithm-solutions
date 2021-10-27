#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Runtime: 8 ms, faster than 72.35% of C++ online submissions for Shuffle String.
Memory Usage: 15.2 MB, less than 74.59% of C++ online submissions for Shuffle String.
*/

class Solution {
public:
	char char_result[101];		// cause we need string's end mark, so set the array's size to max size(100) + 1

	string restoreString(string s, vector<int>& indices) {
		for (int i = 0; i < indices.size(); i++)
		{
			char_result[indices[i]] = s.at(i);
		}

		string result(char_result);
		return result;
	}
};

int main(void) {
	Solution sol = Solution();
	string input1 = "ctunnjrhbbfozbcptydxdcszgvikxofnqolixsqygdotnttxpshfzlplbaednpzzolkfgqylcemcgjhfyszxknkgqxvqaudccixj";
	vector<int> input2 = { 76, 33, 7, 0, 83, 88, 59, 50, 36, 46, 42, 90, 26, 14, 94, 52, 70, 27, 73, 77, 45, 34, 71, 92, 2, 29, 38, 30, 99, 4, 98, 78, 1, 54, 13, 60, 41, 74, 6, 69, 53, 79, 64, 24, 3, 63, 87, 5, 28, 81, 37, 21, 17, 75, 25, 47, 31, 44, 8, 32, 91, 12, 40, 22, 19, 20, 15, 18, 49, 65, 95, 58, 61, 82, 9, 10, 62, 89, 85, 48, 11, 35, 93, 51, 68, 86, 66, 39, 23, 56, 57, 43, 97, 16, 80, 67, 84, 55, 72, 96 };
	sol.restoreString(input1,input2);

	return 0;
}