#include <iostream>
#include <string>
using namespace std;

void solution_11655() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string input;
	getline(cin, input);

	for (int i = 0; i < input.size(); i++)
	{
		// 입력이 들어오면 한 글자씩 읽고, 대문자와 소문자는 뒤로 13글자 보낸 글자를 출력하도록 한다
		int current_character = input.at(i);

		if (current_character >= 65) {
			//대문자 or 소문자일 경우 (65~90)(97~122)
			current_character = current_character + 13;
			if ((current_character > 90 && current_character < 104) || (current_character > 122)) {
				current_character = current_character - 26;
			}
		}
		// space, 숫자는 각각 32, 48~57이므로 변환 없이 출력
		cout << (char)current_character;
	}
}

int main(void) {
	solution_11655();
	return 0;
}