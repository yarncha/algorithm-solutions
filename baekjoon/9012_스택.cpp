#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 단어를 뒤집기 위한 스택
	stack<char> s;

	// 몇 줄이 주어질지를 받아오고 이를 for문으로 반복
	int num_of_commands;
	cin >> num_of_commands;
	cin.ignore();

	string input_string;
	while (num_of_commands != 0)
	{
		//한 줄 입력받기
		getline(cin, input_string);
		input_string.push_back('\n');

		char current_char;	//현재 글자
		int is_vaild = 1;	//이 줄의 괄호 관계가 올바른지
		for (int j = 0; j < input_string.size(); j++)
		{
			// 입력받은 것을 한 글자씩 가져옴
			current_char = input_string[j];
			if (current_char == '(') {
				s.push(current_char);
			}
			else if (current_char == ')') {
				if (s.empty() || s.top() != '(') {
					is_vaild = 0;
					break;
				}
				else {
					s.pop();
				}
			}
		}

		if (is_vaild == 1 && s.empty()) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}

		//스택 비워주기
		while (!s.empty())
		{
			s.pop();
		}

		num_of_commands--;
	}

	return 0;
}