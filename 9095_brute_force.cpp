#include <iostream>
using namespace std;

/*
이번엔 브루트 포스 방법으로 재귀함수를 이용해 풀어봄
입력으로 주어지는 n이 범위가 작으므로, 브루트포스를 이용할 수 있게 됨
*/

int answer;					// 문제의 출력이 될 "n을 1,2,3의 합으로 나타내는 방법의 수"

void CalculateNum(int dest) {
	for (int i = 1; i <= 3; i++)
	{
		int next_dest = dest - i;
		if (next_dest == 0) {
			answer++;
		}
		else if (next_dest > 0) {
			CalculateNum(dest - i);
		}
	}
}

void Solution9095BruteForce() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_testcase;			// 테스트 케이스의 개수
	cin >> num_testcase;

	for (int i = 0; i < num_testcase; i++)
	{
		// 각각의 테스트 케이스에서 답을 구하고 출력
		answer = 0;			// answer 초기화

		int cur_dest;
		cin >> cur_dest;
		CalculateNum(cur_dest);
		cout << answer << "\n";
	}
}

int main(void) {
	Solution9095BruteForce();
	return 0;
}