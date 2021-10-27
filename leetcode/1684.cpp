#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Runtime: 48 ms, faster than 87.49% of C++ online submissions for Count the Number of Consistent Strings.
Memory Usage: 30.2 MB, less than 57.14% of C++ online submissions for Count the Number of Consistent Strings.
*/

class Solution {
public:
    bool is_allowed[26];            // an array to find out which alphabet is allowed, if is_allowed[i] == true, then ith alphabet is in "allowed" string

    int countConsistentStrings(string allowed, vector<string>& words) {
        // set is_allowed array
        for (int i = 0; i < allowed.size(); i++)
        {
            int char_ascii = allowed[i]-97;
            is_allowed[char_ascii] = true;
        }

        int num_of_unconsistent_words = 0;
        for (int j = 0; j < words.size(); j++)
        {
            for (int k = 0; k < words[j].size(); k++)
            {
                int cur_char_ascii = words[j][k] - 97;
                if (!is_allowed[cur_char_ascii]) {
                    num_of_unconsistent_words++;
                    break;
                }
            }
        }

        return words.size() - num_of_unconsistent_words;
    }
};

//int main(void) {
//	Solution sol = Solution();
//
//	sol.qwer();
//
//	return 0;
//}