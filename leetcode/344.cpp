#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
	void reverseString(vector<char>& s) {
		char temp;
		int count = 0;
		while (count < (int)(s.size() - 1 - count)) {
			temp = s[count];
			s[count] = s[s.size() - 1 - count];
			s[s.size() - 1 - count] = temp;
			count++;
		}
	}
};

int main(void) {
	Solution sol = Solution();
	vector<char> v = { };
	vector<char> v22 = { 'h', 'e', 'l', 'l', 'o' };

	sol.reverseString(v);
	sol.reverseString(v22);
	return 0;
}