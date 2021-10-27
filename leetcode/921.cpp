#include <stdio.h>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	int minAddToMakeValid(string S) {
		int result = 0;

		stack<char> s;	//stack to save '('

		for (int i = 0; i < S.size(); i++)
		{
			if (S[i] == '(') {
				s.push('(');
			}
			else {
				if (s.empty()) {
					result++;
				}
				else {
					s.pop();
				}
			}
		}

		result = result + s.size();

		return result;
	}
};

int main(void) {
	Solution sol = Solution();
	string input = "()))(";
	sol.minAddToMakeValid(input);
	return 0;
}