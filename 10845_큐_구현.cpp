#include <iostream>
#include <string>
using namespace std;

struct queue {
	int queue_data[10000];	// 명령의 수가 10000으로 주어져 있으므로 10000으로 설정해 둔다.
	int begin;
	int end;

	queue() {
		begin = 0;
		end = 0;
	}

	void push(int num) {
		queue_data[end] = num;
		end++;
	}

	int pop() {
		if (empty()) {
			return -1;
		}
		return queue_data[begin++];
	}

	int size() {
		return end - begin;
	}

	int empty() {
		if (size() == 0) {
			return 1;
		}
		return 0;
	}

	int front() {
		if (empty()) {
			return -1;
		}
		return queue_data[begin];
	}

	int back() {
		if (empty()) {
			return -1;
		}
		return queue_data[end - 1];
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	queue q;

	int num_of_commands;
	string current_command;     //입력받을 명령
	int value;      //입력받을 값
	cin >> num_of_commands;
	// 명령의 갯수를 입력받고 for문에서 해당 갯수만큼 돌린다.

	for (int i = 0; i < num_of_commands; i++)
	{
		cin >> current_command;

		if (current_command == "push") {
			cin >> value;
			q.push(value);
		}
		else if (current_command == "pop") {
			cout << q.pop() << "\n";
		}
		else if (current_command == "size") {
			cout << q.size() << "\n";
		}
		else if (current_command == "empty") {
			cout << q.empty() << "\n";
		}
		else if (current_command == "front") {
			cout << q.front() << "\n";
		}
		else if (current_command == "back") {
			cout << q.back() << "\n";
		}
	}
	return 0;
}