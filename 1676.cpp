#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int input_number;
	cin >> input_number;

	int number_of_zeros = 0;

	// �μ��� 5�� ���� �͵��� ������ ���ϱ� ���ؼ��� 5�� �����ָ� �ȴ�.
	// 100!�� ��� 100/5�� 20�̹Ƿ� 20���� �ִµ�, �̵� �� 25�� ���� 5*5, 5�� �� �� �̻� �� �ִ� ��쵵 �����Ƿ�
	// �̸� �ٽ� 5�� �������ָ� 25�� ���� �͵��� ���� �� �����Ƿ� �ѹ��� �� �����ָ� �ȴ�.
	while (input_number >= 5)
	{
		number_of_zeros += input_number / 5;
		input_number = input_number / 5;
	}

	cout << number_of_zeros;
	return 0;
}