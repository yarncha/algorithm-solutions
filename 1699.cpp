#include <iostream>
using namespace std;

void Solution1699() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int input_number;						// 1~100000
	cin >> input_number;

	int num_of_square_number[100001];		// 제곱수 합의 최소 개수를 저장할 배열
	num_of_square_number[0] = 0;			// num_of_square_number[4]와 같은 경우를 위해 저장해둠
	num_of_square_number[1] = 1;
	// 1은 초기값으로 설정해 두었으니, 2부터 시작해서 구하려는 수 input_number까지 배열을 채워나감
	for (int i = 2; i <= input_number; i++)
	{
		// 먼저 최소값을 i-1로 설정해 둔 뒤, 다른 제곱을 뺀 값들을 비교하며 어떤 값이 최소인지 찾음
		// ex) 구하려는 i가 24인 경우
		//     num_of_square_number[24-1]이 초기 min_value로 설정되고
		//	   바로 아래의 반복문을 돌며 num_of_square_number[24-4], num_of_square_number[24-9], num_of_square_number[24-16]를 min_value과 비교함
		//	   이 중 최소인 값이 min_value로 설정됨
		int min_value = num_of_square_number[i - 1];
		for (int j = 2; j * j <= i; j++)
		{
			if (min_value > num_of_square_number[i - (j * j)]) {
				min_value = num_of_square_number[i - (j * j)];
			}
		}

		// 최소값을 찾을 경우, 이를 +1해서 num_of_square_number[i]에 저장
		num_of_square_number[i] = min_value + 1;
	}

	cout << num_of_square_number[input_number];
}

int main(void) {
	Solution1699();
	return 0;
}