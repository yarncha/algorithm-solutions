#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	string defangIPaddr(string address) {
		string result = "";

		for (int i = 0; i < address.size(); i++) {
			if (address.at(i) == '.') {
				result.push_back('[');
				result.push_back('.');
				result.push_back(']');
			}
			else {
				result.push_back(address.at(i));
			}
		}

		return result;
	}
};

int main(void) {
	Solution sol = Solution();
	string input = "255.100.50.0";
	cout << sol.defangIPaddr(input) << "\n";
	return 0;
}