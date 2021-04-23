#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 몇 줄이 주어질지를 받아오고 이를 for문으로 반복
	int num_of_commands;
	cin >> num_of_commands;

	stack<int> s;	//사용할 스택
	int input_number;	//입력 숫자
	int counter = 1;	// 수열 이용에 필요한 카운터
	int is_vaild = 1;	//수열을 만들 수 있는지
	string result = "";	//결과

	for (int i = 0; i < num_of_commands; i++)
	{
		cin >> input_number;

		// 입력한 숫자가 스택에 들어간 것보다 작을 경우는 counter이용해서 push
		if (s.size() == 0 || input_number > s.top()) {
			while (counter <= input_number)
			{
				s.push(counter);
				result.push_back('+');
				result.push_back('\n');
				//result += '+';
				counter++;
			}
		}

		// pop을 할 때에는 top에 입력한 원소가 있어야함
		if (s.top() == input_number) {
			s.pop();
			result.push_back('-');
			result.push_back('\n');
			//result += '-';
		}
		else {
			is_vaild = 0;
			//break;
		}

	}

	//이 수열을 만들 수 있는지를 판단
	if (is_vaild == 1) {
		cout << result;
	}
	else {
		cout << "NO\n";
	}

	return 0;
}