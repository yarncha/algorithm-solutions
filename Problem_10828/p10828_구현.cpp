#include <iostream>
#include <string>
using namespace std;

struct Stack {
	int stack_data[10000];
	int size;
	// ����� ���� 10000���� �־��� �����Ƿ� 10000���� ������ �д�.

	Stack() {
		size = 0;
	}

	void push(int num) {
		stack_data[size] = num;
		size++;
	}

	int pop() {
		if (empty()) {
			return -1;
		}
		size--;
		return stack_data[size];
	}

	bool empty() {
		if (size == 0) {
			return true;
		}
		return false;
	}

	int top() {
		if (empty()) {
			return -1;
		}
		return stack_data[size - 1];
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Stack s;

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
			cout << s.pop() << "\n";
		}
		else if (current_command == "size") {
			cout << s.size << "\n";
		}
		else if (current_command == "empty") {
			cout << s.empty() << "\n";
		}
		else if (current_command == "top") {
			cout << s.top() << "\n";
		}
	}
	return 0;
}
