#include <iostream>
#include <string>
#include <stack>
using namespace std;

int qwer(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// �ܾ ������ ���� ����
	stack<char> s;

	//�±� ������ ������ bool
	bool in_tag = false;

	// ù��° �ٿ��� ���� �� �޾ƿ���
	string input_string;
	getline(cin, input_string);
	input_string.push_back('\n');

	string result_string = "";
	char current_char;
	for (int j = 0; j < input_string.size(); j++)
	{
		current_char = input_string[j];

		if (in_tag) {
			result_string.push_back(current_char);

			if (current_char == '>') {
				in_tag = false;
			}
		}
		else {
			if (current_char == '<') {
				in_tag = true;
			}

			if (current_char == ' ' || current_char == '\n' || in_tag) {
				while (!s.empty())
				{
					result_string.push_back(s.top());
					s.pop();
				}
				result_string.push_back(current_char);
			}
			else {
				s.push(current_char);
			}
		}
	}

	cout << result_string << "\n";
	return 0;
}