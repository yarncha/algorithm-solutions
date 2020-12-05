#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	stack<int> s;

	int num_of_commands;
	string current_command;     //�Է¹��� ���
	int value;      //�Է¹��� ��
	cin >> num_of_commands;
	// ����� ������ �Է¹ް� for������ �ش� ������ŭ ������.

	for (int i = 0; i < num_of_commands; i++)
	{
		cin >> current_command;

		if (current_command == "push") {
			cin >> value;
			s.push(value);
		}
		else if (current_command == "pop") {
			if (s.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << s.top() << "\n";
				s.pop();
			}
			// Stack ���̺귯�������� pop�� � ���� ��ȯ���� �ʰ�, void�� �����Ǿ������Ƿ� top�� �����ϵ��� �Ѵ�.
		}
		else if (current_command == "size") {
			cout << s.size() << "\n";
		}
		else if (current_command == "empty") {
			cout << s.empty() << "\n";
		}
		else if (current_command == "top") {
			if (s.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << s.top() << "\n";
			}
		}
	}

	return 0;
}
