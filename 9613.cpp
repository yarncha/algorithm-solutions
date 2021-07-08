#include <iostream>
#include <string>
using namespace std;

// 최대공약수를 구하는 공식
// 시간 복잡도 O(log(n+m))
int gcd(int x, int y) {
	while (y > 0)
	{
		int mod_value = x % y;
		x = y, y = mod_value;
	}
	return x;
}

void Solution9613() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_test_cases;	// 테스트 케이스의 개수
	cin >> num_of_test_cases;

	int num_of_inputs, input;		// gcd를 구하기 위한 수의 개수, gcd를 구하기 위한 수
	int input_array[100];	// gcd를 구하기 위한 수를 저장할 배열
	long long sum_of_gcd = 0;	// 각 테스트케이스마다 gcd 합을 구할 변수인데, 수의 개수가 100개이고, 모든 수가 1000000일 경우는
								// 1,000,000*4950로 int 값을 넘어가게 되므로, 더 큰 수를 이용해 저장한다
	for (int i = 0; i < num_of_test_cases; i++)
	{
		// 입력을 받아서 배열에 저장함
		cin >> num_of_inputs;
		for (int j = 0; j < num_of_inputs; j++)
		{
			cin >> input;
			input_array[j] = input;
		}

		for (int x = 0; x < num_of_inputs; x++)
		{
			for (int y = x + 1; y < num_of_inputs; y++)
			{
				sum_of_gcd += gcd(input_array[x], input_array[y]);
			}
		}
		cout << sum_of_gcd << "\n";

		sum_of_gcd = 0;
	}
}

int main(void) {
	Solution9613();
	return 0;
}