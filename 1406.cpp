#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// �ʱ� ���ڿ��� �޾ƿ�
	string initial_str;
	cin >> initial_str;

	//����� ����
	stack<char> left;	//Ŀ�� ���� ���ڿ���
	stack<char> right;	//Ŀ�� ������ ���ڿ���

	// �� ó������ ��� ���ڵ��� Ŀ�� ���ʿ� ��ġ�ϹǷ� left stack�� �־��ش�.
	for (int j = 0; j < initial_str.size(); j++) {
		left.push(initial_str[j]);
	}

	// �� ���� �־������� �޾ƿ��� �̸� for������ �ݺ�
	int num_of_commands;
	cin >> num_of_commands;
	cin.ignore();

	string command;	//�Է� ��ɾ�
	for (int i = 0; i < num_of_commands; i++)
	{
		//�� �� �Է¹ޱ�
		getline(cin, command);
		//command.push_back('\n');

		if (command == "L")
		{
			if (!left.size() == 0) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (command == "D")
		{
			if (!right.size() == 0) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (command == "B")
		{
			if (!left.size() == 0) {
				left.pop();
			}
		}
		else if (command[0] == 'P') {
			left.push(command[2]);
		}
	}

	// ��� ��ɾ ������ �� �����⿡ �ִ� ���ڿ� ���ϱ�
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}

	while (!right.empty())
	{
		cout << right.top();
		right.pop();
	}

	return 0;
}