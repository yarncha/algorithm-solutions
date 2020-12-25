#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_partition = 0;

	bool is_laser = false;	// 다음 들어올 글자가 레이저인지 아닌지를 파악
	stack<char> s;	//"("를 저장할 스택

	//입력 받기
	string input;
	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		char current_char = input[i];
		if (current_char == '(') {
			s.push(current_char);
			is_laser = true;
		}
		else {
			s.pop();
			if (is_laser) {
				is_laser = false;
				num_of_partition += s.size();
			}
			else {
				num_of_partition++;
			}
		}
	}
	cout << num_of_partition;
	return 0;
}