#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
int frequency[1000001];	//수의 빈도수를 저장할 벡터

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_input, input;
	cin >> num_of_input;

	stack<int> s;	// 입력 수열의 인덱스를 저장할 스택
	vector<int> inputs(num_of_input);	// 입력 수열의을 저장할 벡터
	vector<int> ngf(num_of_input);	// 입력 수열의 오등큰수를 저장할 벡터

	//처음 입력은 먼저 넣어두기
	cin >> input;
	inputs[0] = input;
	frequency[input] = frequency[input] + 1;
	s.push(0);

	//빈도수 계산 미리
	for (int k = 1; k < num_of_input; k++)
	{
		cin >> input;
		inputs[k] = input;
		frequency[input] = frequency[input] + 1;
	}

	// 두 번째 입력부터는 스택의 값과 비교해서 넣기
	for (int i = 1; i < num_of_input; i++)
	{
		while (!s.empty() && frequency[inputs[i]] > frequency[inputs[s.top()]]) {
			ngf[s.top()] = inputs[i];
			s.pop();
		}
		s.push(i);
	}

	// 아직 처리 안된것들은 -1로 지정해주기
	while (!s.empty())
	{
		ngf[s.top()] = -1;
		s.pop();
	}

	for (int j = 0; j < num_of_input - 1; j++)
	{
		cout << ngf[j] << " ";
	}
	cout << ngf[num_of_input - 1];

	return 0;
}