#include <iostream>
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
	while (num_of_commands != 0)
	{
		//�� �� �Է¹ޱ�
		getline(cin, input_string);
		input_string.push_back('\n');

		char current_char;	//���� ����
		int is_vaild = 1;	//�� ���� ��ȣ ���谡 �ùٸ���
		for (int j = 0; j < input_string.size(); j++)
		{
			// �Է¹��� ���� �� ���ھ� ������
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

		//���� ����ֱ�
		while (!s.empty())
		{
			s.pop();
		}

		num_of_commands--;
	}

	return 0;
}