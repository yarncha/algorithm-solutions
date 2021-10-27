#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
Memory Usage: 6.3 MB, less than 63.15% of C++ online submissions for Valid Parentheses.
*/

class Solution {
public:
	bool isValid(string s) {
		stack<char> parentheses_stack;

		char current_char;
		// read the string s one letter at a time
		for (int i = 0; i < s.size(); i++)
		{
			current_char = s.at(i);
			if (current_char == '{' || current_char == '(' || current_char == '[') {
				// if current_char is a opening parentheses, put it in parentheses_stack
				parentheses_stack.push(current_char);
			}
			else if (current_char == '}') {
				if (parentheses_stack.size() == 0 || parentheses_stack.top() == '(' || parentheses_stack.top() == '[') {
					return false;
				}
				else if (parentheses_stack.top() == '{') {
					parentheses_stack.pop();
				}
			}
			else if (current_char == ']') {
				if (parentheses_stack.size() == 0 || parentheses_stack.top() == '(' || parentheses_stack.top() == '{') {
					return false;
				}
				else if (parentheses_stack.top() == '[') {
					parentheses_stack.pop();
				}
			}
			else if (current_char == ')') {
				if (parentheses_stack.size() == 0 || parentheses_stack.top() == '{' || parentheses_stack.top() == '[') {
					return false;
				}
				else if (parentheses_stack.top() == '(') {
					parentheses_stack.pop();
				}
			}
		}

		// if there's still anything left in stack when you've read all characters,
		// that string is not a vaild string.
		if (parentheses_stack.size() == 0) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main(void) {
	Solution sol = Solution();
	string input = "{{}}";
	sol.isValid(input);

	return 0;
}