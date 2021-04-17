#include <iostream>
#include <string>
using namespace std;

void solution_10820() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int character_counter[4] = { 0, };
	string input;
	while (getline(cin, input)) {
		for (int i = 0; i < input.size(); i++)
		{
			if (input.at(i) == ' ') {
				// space일경우
				character_counter[3] = character_counter[3] + 1;
			}
			else if (input.at(i) <= '9') {
				// 숫자일 경우
				character_counter[2] = character_counter[2] + 1;
			}
			else if (input.at(i) <= 'Z') {
				// 대문자일경우
				character_counter[1] = character_counter[1] + 1;
			}
			else {
				// 소문자일경우
				character_counter[0] = character_counter[0] + 1;
			}
		}
		cout << character_counter[0] << " " << character_counter[1] << " " << character_counter[2] << " " << character_counter[3]<<"\n";
		character_counter[0] = 0;
		character_counter[1] = 0;
		character_counter[2] = 0;
		character_counter[3] = 0;
	}
}

int main(void) {
	solution_10820();
	return 0;
}
