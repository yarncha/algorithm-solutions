#include <iostream>
#include <vector>
using namespace std;

void solution_6588() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	vector<int> primes;
	//int primes[999999];	// 에라토스테네스의 체를 이용해 구한 소수를 담을 배열
	int num_of_prime = 0;
	bool is_removed[1000001] = { false };	// 체를 통해 해당 수가 제거되었는지를 알려주는 배열
	int end = 1000000;	// ~end 사이의 소수를 구할 것

	for (int i = 2; i <= end; i++) {
		if (is_removed[i] == false) {
			primes.push_back(i);
			num_of_prime++;
			//primes[0] = 2;
			//primes[num_of_prime++] = i;
			// 지워지지 않은 수 중 가장 작은 수는 소수로 마킹해두고,
			for (int j = i + i; j <= end; j += i) {
				is_removed[j] = true;
			}
			// i*i부터 시작하여 그 수의 배수들을 전부 제거한다.
			// 하지만 i*i가 범위를 넘어갈 수 있어 i+i또는 i*2로 대체하여 사용한다
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