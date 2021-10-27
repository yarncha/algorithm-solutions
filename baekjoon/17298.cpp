#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_input, input;
	cin >> num_of_input;

	stack<int> s;	// 입력 수열의 인덱스를 저장할 스택
	vector<int> inputs(num_of_input);	// 입력 수열을 저장할 벡터
	vector<int> nge(num_of_input);	// 입력 수열의 오큰수를 저장할 벡터

	//처음 입력은 먼저 넣어두기
	cin >> input;
	inputs[0] = input;
	s.push(0);

	// 두 번째 입력부터는 스택의 값과 비교해서 넣기
	for (int i = 1; i < num_of_input; i++)
	{
		cin >> input;
		inputs[i] = input;

		while (!s.empty() && input > inputs[s.top()]) {
			nge[s.top()] = input;
			s.pop();
		}
		s.push(i);
	}

	// 아직 처리 안된것들은 -1로 지정해주기
	while (!s.empty())
	{
		nge[s.top()] = -1;
		s.pop();
	}

	for (int j = 0; j < num_of_input - 1; j++)
	{
		cout << nge[j] << " ";
	}
	cout << nge[num_of_input - 1];

	return 0;
}