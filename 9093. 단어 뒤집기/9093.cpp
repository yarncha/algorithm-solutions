#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// �ܾ ������ ���� ����
	stack<char> s;

	// �� ���� �־������� �޾ƿ��� �̸� for������ �ݺ�
	int num_of_commands;
	cin >> num_of_commands;
	cin.ignore();

	string input_string;
	string result_string = "";
	while (num_of_commands != 0)
	{
		getline(cin, input_string);
		input_string.push_back('\n');

		char current_char;
		for (int j = 0; j < input_string.size(); j++)
		{
			current_char = input_string[j];
			//������ ��� ���� result_string�� ��������
			if (current_char == ' ' || current_char == '\n') {
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
		num_of_commands--;
	}

	cout << result_string << "\n";

	return 0;
}