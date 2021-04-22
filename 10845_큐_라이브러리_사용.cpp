#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	queue<int> q;

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
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (current_command == "size") {
			cout << q.size() << "\n";
		}
		else if (current_command == "empty") {
			cout << q.empty() << "\n";
		}
		else if (current_command == "front") {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
			}
		}
		else if (current_command == "back") {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.back() << "\n";
			}
		}
	}

	return 0;
}
