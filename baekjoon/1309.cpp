#include <iostream>
using namespace std;

void Solution1309() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int size_of_cage_height;		// 우리의 세로 길이 (1~100000)
	cin >> size_of_cage_height;

	long long num_of_cases_to_arrange_lions[100001][3];		// 사자를 2xi크기의 우리에 배치할 수 있는 경우의 수.
															// j는 마지막에 배치된 사자의 위치
															// (0=왼쪽에 배치됨, 1=오른쪽에 배치됨, 2=배치되지 않음)

	// 2x1크기의 우리에 사자를 배치하는 경우의 수를 초기값으로 넣어줌 (각각의 경우는 하나씩밖에 없다)
	num_of_cases_to_arrange_lions[1][0] = 1;
	num_of_cases_to_arrange_lions[1][1] = 1;
	num_of_cases_to_arrange_lions[1][2] = 1;

	// 2x2부터 시작하며 사자를 배치하는 경우의 수를 구해 나감
	for (int i = 2; i <= size_of_cage_height; i++)
	{
		// 2xi 크기의 우리에 사자를 배치할 때, 마지막 칸의 왼쪽에 사자가 있는 경우의 수(num_of_cases_to_arrange_lions[i][0])는
		// 이전에(i-1) 사자가 오른쪽에 있었을 경우(num_of_cases_to_arrange_lions[i-1][1])나 아무 칸에도 없었을 경우(num_of_cases_to_arrange_lions[i-1][2])를 더해주면 된다
		num_of_cases_to_arrange_lions[i][0] = (num_of_cases_to_arrange_lions[i - 1][1] + num_of_cases_to_arrange_lions[i - 1][2]) % 9901;
		num_of_cases_to_arrange_lions[i][1] = (num_of_cases_to_arrange_lions[i - 1][0] + num_of_cases_to_arrange_lions[i - 1][2]) % 9901;
		// 마지막 칸에 사자가 없을 경우는 모든 경우의 수(이전에 왼쪽에 있었을 경우, 오른쪽에 있었을 경우, 없었을 경우) 모두를 다 더해준다.
		num_of_cases_to_arrange_lions[i][2] = (num_of_cases_to_arrange_lions[i - 1][0] + num_of_cases_to_arrange_lions[i - 1][1] + num_of_cases_to_arrange_lions[i - 1][2]) % 9901;
	}

	long long sum = num_of_cases_to_arrange_lions[size_of_cage_height][0] + num_of_cases_to_arrange_lions[size_of_cage_height][1] + num_of_cases_to_arrange_lions[size_of_cage_height][2];
	cout << sum % 9901;
}

int main(void) {
	Solution1309();
	return 0;
}