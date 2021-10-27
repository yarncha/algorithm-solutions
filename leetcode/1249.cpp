﻿#include <stdio.h>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

/*
Runtime: 48 ms, faster than 31.72% of C++ online submissions for Minimum Remove to Make Valid Parentheses.
Memory Usage: 11.9 MB, less than 49.60% of C++ online submissions for Minimum Remove to Make Valid Parentheses.
*/

class Solution {
public:
	string minRemoveToMakeValid(string s) {
		stack<int> stack_for_index;	//stack to save index of '('
		string result_string = "";

		// count wrong parentheses with stack & make string
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(') {
				stack_for_index.push(result_string.size());
				result_string.push_back(s[i]);
			}
			else if (s[i] == ')') {
				if (!stack_for_index.empty()) {
					stack_for_index.pop();
					result_string.push_back(s[i]);
				}
			}
			else {
				result_string.push_back(s[i]);
			}
		}
		// now "stack_for_characters.size()" is the number of wrong "left" parentheses

		// remove wrong left parentheses
		while (!stack_for_index.empty())
		{
			result_string.erase(stack_for_index.top(), 1);
			stack_for_index.pop();
		}

		return result_string;
	}
};

int main(void) {
	Solution sol = Solution();
	string input = "lee(t(c)o)de)";
	cout << sol.minRemoveToMakeValid(input) << "\n";
	return 0;
}