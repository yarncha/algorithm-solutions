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
	string current_command;     //입력받을 명령
	int value;      //입력받을 값
	cin >> num_of_commands;
	// 명령의 갯수를 입력받고 for문에서 해당 갯수만큼 돌린다.

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
			// Stack 라이브러리에서는 pop이 어떤 값을 반환하지 않고, void로 구현되어있으므로 top을 리턴하도록 한다.
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
