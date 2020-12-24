#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 초기 문자열을 받아옴
	string initial_str;
	cin >> initial_str;

	//사용할 스택
	stack<char> left;	//커서 왼쪽 문자열들
	stack<char> right;	//커서 오른쪽 문자열들

	// 맨 처음에는 모든 문자들이 커서 왼쪽에 위치하므로 left stack에 넣어준다.
	for (int j = 0; j < initial_str.size(); j++) {
		left.push(initial_str[j]);
	}

	// 몇 줄이 주어질지를 받아오고 이를 for문으로 반복
	int num_of_commands;
	cin >> num_of_commands;
	cin.ignore();

	string command;	//입력 명령어
	for (int i = 0; i < num_of_commands; i++)
	{
		//한 줄 입력받기
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

	// 모든 명령어를 수행한 후 편집기에 있는 문자열 구하기
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