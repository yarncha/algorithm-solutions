#include <iostream>
#include <vector>
using namespace std;

void Solution17103() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 1. 먼저 에라토스테네스의 체를 이용해 소수들을 구해 준다.
	vector<int> primes;		// 에라토스테네스의 체를 이용해 구한 소수를 담을 배열
	int num_of_prime = 0;
	bool is_removed[1000001] = { false };	// 체를 통해 해당 수가 제거되었는지를 알려주는 배열
	int end = 1000000;	// ~end 사이의 소수를 구할 것

	for (int i = 2; i <= end; i++) {
		if (is_removed[i] == false) {
			primes.push_back(i);
			num_of_prime++;
			// 지워지지 않은 수 중 가장 작은 수는 소수로 마킹해두고,
			for (int j = i + i; j <= end; j += i) {
				is_removed[j] = true;
			}
			// i*i부터 시작하여 그 수의 배수들을 전부 제거한다.
			// 하지만 i*i가 범위를 넘어갈 수 있어 i+i또는 i*2로 대체하여 사용한다
		}
	}


	// 2. 짝수 input을 입력받으면,
	// 이를 두 소수의 합으로 나타낼 수 있는 개수(골드바흐 파티션의 개수) 구하기
	int num_of_test_cases;	// 테스트 케이스의 개수(1~100)
	int input;				// 테스트 케이스. 이 짝수의 골드바흐 파티션 구하기(2~1,000,000)
	int num_of_partition = 0;

	cin >> num_of_test_cases;
	while (num_of_test_cases > 0)
	{
		cin >> input;

		for (int k = 0; k < num_of_prime; k++)
		{
			int prime_to_compare = primes[k];
			if (input - prime_to_compare <= 0 || (2 * prime_to_compare) > input) {
				break;
			}
			else if (is_removed[input - prime_to_compare] == false) {
				num_of_partition++;
			}
		}
		cout << num_of_partition << "\n";
		num_of_partition = 0;
		num_of_test_cases--;
	}
}

int main(void) {
	Solution17103();
	return 0;
}