#include <iostream>
using namespace std;
int num_of_cases_to_make_sum[201][201] = { 0, };		// i를 j자리의 합으로 만들 수 있는 경우의 수

int CalculateCase(int result_number, int num_of_elements) {
	if (num_of_cases_to_make_sum[result_number][num_of_elements] > 0) {
		// 만약 배열에 저장된 값이 있었을 경우에는 이를 리턴
		return num_of_cases_to_make_sum[result_number][num_of_elements];
	}

	// 없었을 경우에는 계산해봄
	long long case_of_sum = 0;
	for (int i = result_number; i >= 0; i--)
	{
		case_of_sum += CalculateCase(i, num_of_elements - 1);
	}

	num_of_cases_to_make_sum[result_number][num_of_elements] = case_of_sum % 1000000000;
	return num_of_cases_to_make_sum[result_number][num_of_elements];
}

void Solution2225() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int result_number, num_of_elements;			//만들어야 할 수와 몇 개의 정수로 만들어야할지 개수
	cin >> result_number >> num_of_elements;

	// (x,1), (0,y) 1으로 채워놓기
	for (int j = 0; j <= result_number; j++)
	{
		num_of_cases_to_make_sum[j][1] = 1;
	}
	for (int j = 0; j <= num_of_elements; j++)
	{
		num_of_cases_to_make_sum[0][j] = 1;
	}

	// 재귀적으로 계산
	CalculateCase(result_number, num_of_elements);

	// 출력
	cout << num_of_cases_to_make_sum[result_number][num_of_elements];
}

int main(void) {
	Solution2225();
	return 0;
}
