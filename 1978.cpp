#include <iostream>
#include <string>
using namespace std;

// � �� number�� �Ҽ������� �Ǵ��ϱ� ���� �Լ�
bool is_prime(int number) {
	// 2���� ���� ������ �Ҽ��� �ƴ�
	if (number < 2)
	{
		return false;
	}

	// ��Ʈ number���� ���� ���� �߿��� number�� ������ �������� �ϴ� ���� �ִ��� �Ǵ�
	for (int i = 2; i * i <= number; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_input, current;
	cin >> num_of_input;

	int num_of_prime = 0;
	for (int i = 0; i < num_of_input; i++)
	{
		cin >> current;
		if (is_prime(current)) {
			num_of_prime++;
		}
	}

	cout << num_of_prime;

	return 0;
}