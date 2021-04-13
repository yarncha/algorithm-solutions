#include <iostream>
#include <vector>
using namespace std;

void solution_6588() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	vector<int> primes;
	//int primes[999999];	// �����佺�׳׽��� ü�� �̿��� ���� �Ҽ��� ���� �迭
	int num_of_prime = 0;
	bool is_removed[1000001] = { false };	// ü�� ���� �ش� ���� ���ŵǾ������� �˷��ִ� �迭
	int end = 1000000;	// ~end ������ �Ҽ��� ���� ��

	for (int i = 2; i <= end; i++) {
		if (is_removed[i] == false) {
			primes.push_back(i);
			num_of_prime++;
			//primes[0] = 2;
			//primes[num_of_prime++] = i;
			// �������� ���� �� �� ���� ���� ���� �Ҽ��� ��ŷ�صΰ�,
			for (int j = i + i; j <= end; j += i) {
				is_removed[j] = true;
			}
			// i*i���� �����Ͽ� �� ���� ������� ���� �����Ѵ�.
			// ������ i*i�� ������ �Ѿ �� �־� i+i�Ǵ� i*2�� ��ü�Ͽ� ����Ѵ�
		}
	}

	int input;
	cin >> input;
	while (input > 0)
	{
		for (int k = 0; k < num_of_prime; k++)
		{
			int prime_to_compare = primes[k];
			if (input - prime_to_compare <= 0) {
				cout << "Goldbach's conjecture is wrong.";
				return;
			}
			else if (is_removed[input - prime_to_compare] == false) {
				cout << input << " = " << prime_to_compare << " + " << input - prime_to_compare << "\n";
				break;
			}
		}
		cin >> input;
	}
}

int main(void) {
	solution_6588();
	return 0;
}