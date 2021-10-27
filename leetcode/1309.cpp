#include <iostream>
#include <string>
using namespace std;

/*

*/

class solution {
public:
    string freqalphabets(string s) {
        // 한글자씩 읽으면서 아스키코드 참고해서 바꿔주기
        string result = "";

        cout << "qwerqwerq";
        for (int i = 0; i < s.size(); i++)
        {
            int integer_value = s[i] - 47;
            if (integer_value<10) {
                result += to_string(integer_value);
            }
            else {
                result += to_string(integer_value);
                result += "#";
            }
        }

        return result;
    }
};

int main(void) {
	solution sol = solution();

	sol.freqalphabets("");

	return 0;
}