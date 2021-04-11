#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_input, input;
	cin >> num_of_input;

	stack<int> s;	// �Է� ������ �ε����� ������ ����
	vector<int> inputs(num_of_input);	// �Է� ������ ������ ����
	vector<int> nge(num_of_input);	// �Է� ������ ��ū���� ������ ����

	//ó�� �Է��� ���� �־�α�
	cin >> input;
	inputs[0] = input;
	s.push(0);

	// �� ��° �Էº��ʹ� ������ ���� ���ؼ� �ֱ�
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

	// ���� ó�� �ȵȰ͵��� -1�� �������ֱ�
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