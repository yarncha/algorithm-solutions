#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

/*

Runtime: 8 ms, faster than 47.61% of C++ online submissions for Crawler Log Folder.
Memory Usage: 10.6 MB, less than 33.37% of C++ online submissions for Crawler Log Folder.

*/

// reads the given log which performs some position moving actions
// and get **the minimum counts** to move the position at last log to main(root) folder
// to find the answer, use stack for save depth of current position

class Solution {
public:
	int minOperations(vector<string>& logs) {
		stack<int> s;
		for (int i = 0; i < logs.size(); i++)
		{
			if (logs[i] == "./") {
			}
			else if (logs[i] == "../") {
				// if current log is "../", move to the parent folder and pop one element in stack 
				// if there 's nothing in stack, do nothing
				if (s.size() > 0) {
					s.pop();
				}
			}
			else {
				// if current log is "x/", move to the x folder and push one element in stack 
				s.push(0);
			}
		}

		// stack's size'll be the depth of folder
		return s.size();
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	sol.minOperations();
//
//	return 0;
//}