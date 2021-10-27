#include <iostream>
using namespace std;

/*

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count Sorted Vowel Strings.
Memory Usage: 5.7 MB, less than 96.36% of C++ online submissions for Count Sorted Vowel Strings.

*/

class Solution {
public:
	int countVowelStrings(int n) {
		// the length of string to make "n" is given
		// so we should get the number of cases to make lexicographical strings which have n length  

		int num_of_strings[51][5] = { 0, };      // number of lexicographically sorted strings that have a length of i character
										// and ends with j(a=0, e=1, i=2, o=3, u=4)

		for (int i = 0; i < 5; i++)
		{
			// with the length 1, we have only one case.
			num_of_strings[1][i] = 1;
		}

		for (int j = 2; j <= n; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				for (int m = 0; m <= k; m++)
				{
					num_of_strings[j][k] += num_of_strings[j - 1][m];
				}
			}
		}

		int result = 0;
		for (int p = 0; p < 5; p++)
		{
			result += num_of_strings[n][p];
		}
		return result;
	}
};

int main(void) {
	Solution sol = Solution();

	cout << sol.countVowelStrings(33);

	return 0;
}