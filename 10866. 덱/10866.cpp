#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	deque<int> d;

	int num_of_commands;
	string current_command;     //입력받을 명령
	int value;      //입력받을 값
	cin >> num_of_commands;
	// 명령의 갯수를 입력받고 for문에서 해당 갯수만큼 돌린다.

	for (int i = 0; i < num_of_commands; i++)
	{
		cin >> current_command;

		if (current_command == "push_front") {
			cin >> value;
			d.push_front(value);
		}
		else if (current_command == "push_back") {
			cin >> value;
			d.push_back(value);
		}
		else if (current_command == "pop_front") {
			if (d.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << d.front() << "\n";
				d.pop_front();
			}
		}
		else if (current_command == "pop_back") {
			if (d.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << d.back() << "\n";
				d.pop_back();
			}
		}
		else if (current_command == "size") {
			cout << d.size() << "\n";
		}
		else if (current_command == "empty") {
			cout << d.empty() << "\n";
		}
		else if (current_command == "front") {
			if (d.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << d.front() << "\n";
			}
		}
		else if (current_command == "back") {
			if (d.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << d.back() << "\n";
			}
		}
	}

	return 0;
}
