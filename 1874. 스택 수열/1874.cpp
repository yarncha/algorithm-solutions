#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// �� ���� �־������� �޾ƿ��� �̸� for������ �ݺ�
	int num_of_commands;
	cin >> num_of_commands;

	stack<int> s;	//����� ����
	int input_number;	//�Է� ����
	int counter = 1;	// ���� �̿뿡 �ʿ��� ī����
	int is_vaild = 1;	//������ ���� �� �ִ���
	string result = "";	//���

	for (int i = 0; i < num_of_commands; i++)
	{
		cin >> input_number;

		// �Է��� ���ڰ� ���ÿ� �� �ͺ��� ���� ���� counter�̿��ؼ� push
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

		// pop�� �� ������ top�� �Է��� ���Ұ� �־����
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

	//�� ������ ���� �� �ִ����� �Ǵ�
	if (is_vaild == 1) {
		cout << result;
	}
	else {
		cout << "NO\n";
	}

	return 0;
}