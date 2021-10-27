#include <stdio.h>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

/*
Runtime: 28 ms, faster than 65.85% of C++ online submissions for Remove All Adjacent Duplicates In String.
Memory Usage: 11 MB, less than 45.56% of C++ online submissions for Remove All Adjacent Duplicates In String.
*/

class Solution {
public:
	string removeDuplicates(string S) {
		stack<char> char_stack;	//stack to save characters

		// eliminate duplicate character
		for (int i = S.size() - 1; i >= 0; i--)
		{
			if (!char_stack.empty() && char_stack.top() == S[i]) {
				char_stack.pop();
			}
			else {
				char_stack.push(S[i]);
			}
		}

		// make elements of stack to string
		string result = "";
		while (!char_stack.empty()) {

			result.push_back(char_stack.top());
			char_stack.pop();
		}

		return result;
	}
};

int main(void) {
	Solution sol = Solution();
	string input = "abbaca";
	cout << sol.removeDuplicates(input) << "\n";
	return 0;
}