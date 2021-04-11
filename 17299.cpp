#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
int frequency[1000001];	//���� �󵵼��� ������ ����

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_input, input;
	cin >> num_of_input;

	stack<int> s;	// �Է� ������ �ε����� ������ ����
	vector<int> inputs(num_of_input);	// �Է� �������� ������ ����
	vector<int> ngf(num_of_input);	// �Է� ������ ����ū���� ������ ����

	//ó�� �Է��� ���� �־�α�
	cin >> input;
	inputs[0] = input;
	frequency[input] = frequency[input] + 1;
	s.push(0);

	//�󵵼� ��� �̸�
	for (int k = 1; k < num_of_input; k++)
	{
		cin >> input;
		inputs[k] = input;
		frequency[input] = frequency[input] + 1;
	}

	// �� ��° �Էº��ʹ� ������ ���� ���ؼ� �ֱ�
	for (int i = 1; i < num_of_input; i++)
	{
		while (!s.empty() && frequency[inputs[i]] > frequency[inputs[s.top()]]) {
			ngf[s.top()] = inputs[i];
			s.pop();
		}
		s.push(i);
	}

	// ���� ó�� �ȵȰ͵��� -1�� �������ֱ�
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