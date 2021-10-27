#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string interpret(string command) {
		string result = "";

		int index = 0;
		while (index < command.size())
		{
			if (command.at(index) == 'G') {
				result += "G";
			}
			else if (command.at(index) == '(') {
				index++;
				if (command.at(index) == ')') {
					result += "o";
				}
				else {
					result += "al";
					index += 2;
				}
			}
			index++;
		}

		return result;
	}
};

//int main(void) {
//	Solution sol = Solution();
//
//	sol.qwer();
//
//	return 0;
//}