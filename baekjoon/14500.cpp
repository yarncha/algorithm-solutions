#include <iostream>
using namespace std;

// 그냥... 정말 모든 모양에 대해서 다 해보는 문제였음 손이 아픈(?) 문제였다

void Solution14500() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 1. 값 입력 받기
	int background[500][500];       // 주어진 종이
	int n, m;                       // 종이의 가로 사이즈 n, 세로 사이즈 m
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 종이에 쓰여 있는 수를 입력받음
			cin >> background[i][j];
		}
	}

	// 2. 모든 경우에 대해서 계산
	int max_value = 0;              // 테트로미노로 가려진 수의 총합의 최댓값. 초기값을 0으로 해 둔다

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// ㅁㅁㅁㅁ
			if (j + 3 < m) {
				int sum = background[i][j] + background[i][j + 1] + background[i][j + 2] + background[i][j + 3];
				if (max_value < sum) max_value = sum;
			}

			// ㅁ
			// ㅁ
			// ㅁ
			// ㅁ
			if (i + 3 < n) {
				int sum = background[i][j] + background[i + 1][j] + background[i + 2][j] + background[i + 3][j];
				if (max_value < sum) max_value = sum;
			}

			// ㅁ
			// ㅁ
			// ㅁㅁ
			if (i + 2 < n && j + 1 < m) {
				int sum = background[i][j] + background[i + 1][j] + background[i + 2][j] + background[i + 2][j + 1];
				if (max_value < sum) max_value = sum;
			}

			//     ㅁ
			// ㅁㅁㅁ
			if (i - 1 >= 0 && j + 2 < m) {
				int sum = background[i][j] + background[i][j + 1] + background[i][j + 2] + background[i - 1][j + 2];
				if (max_value < sum) max_value = sum;
			}

			// ㅁㅁ
			//   ㅁ
			//   ㅁ
			if (i + 2 < n && j + 1 < m) {
				int sum = background[i][j] + background[i][j + 1] + background[i + 1][j + 1] + background[i + 2][j + 1];
				if (max_value < sum) max_value = sum;
			}

			// ㅁㅁㅁ
			// ㅁ
			if (i + 1 < n && j + 2 < m) {
				int sum = background[i][j] + background[i + 1][j] + background[i][j + 1] + background[i][j + 2];
				if (max_value < sum) max_value = sum;
			}

			//   ㅁ
			//   ㅁ
			// ㅁㅁ
			if (i + 2 < n && j - 1 >= 0) {
				int sum = background[i][j] + background[i + 1][j] + background[i + 2][j] + background[i + 2][j - 1];
				if (max_value < sum) max_value = sum;
			}

			// ㅁㅁㅁ
			//     ㅁ
			if (i + 1 < n && j + 2 < m) {
				int sum = background[i][j] + background[i][j + 1] + background[i][j + 2] + background[i + 1][j + 2];
				if (max_value < sum) max_value = sum;
			}

			// ㅁㅁ
			// ㅁ
			// ㅁ
			if (i + 2 < n && j + 1 < m) {
				int sum = background[i][j] + background[i][j + 1] + background[i + 1][j] + background[i + 2][j];
				if (max_value < sum) max_value = sum;
			}

			// ㅁ
			// ㅁㅁㅁ
			if (i + 1 < n && j + 2 < m) {
				int sum = background[i][j] + background[i + 1][j] + background[i + 1][j + 1] + background[i + 1][j + 2];
				if (max_value < sum) max_value = sum;
			}

			//   ㅁㅁ
			// ㅁㅁ
			if (i - 1 >= 0 && j + 2 < m) {
				int sum = background[i][j] + background[i][j + 1] + background[i - 1][j + 1] + background[i - 1][j + 2];
				if (max_value < sum) max_value = sum;
			}

			//   ㅁ
			// ㅁㅁ
			// ㅁ
			if (i + 2 < n && j - 1 >= 0) {
				int sum = background[i][j] + background[i + 1][j] + background[i + 1][j - 1] + background[i + 2][j - 1];
				if (max_value < sum) max_value = sum;
			}

			// ㅁㅁ
			//   ㅁㅁ
			if (i + 1 < n && j + 2 < m) {
				int sum = background[i][j] + background[i][j + 1] + background[i + 1][j + 1] + background[i + 1][j + 2];
				if (max_value < sum) max_value = sum;
			}

			// ㅁ
			// ㅁㅁ
			//   ㅁ
			if (i + 2 < n && j + 1 < m) {
				int sum = background[i][j] + background[i + 1][j] + background[i + 1][j + 1] + background[i + 2][j + 1];
				if (max_value < sum) max_value = sum;
			}

			//   ㅁ
			// ㅁㅁㅁ  and  ㅁㅁㅁ
			//                ㅁ
			if (j + 2 < m) {
				int sum = background[i][j] + background[i][j + 1] + background[i][j + 2];
				if (i - 1 >= 0) {
					int sum2 = sum + background[i - 1][j + 1];
					if (max_value < sum2) max_value = sum2;
				}
				if (i + 1 < n) {
					int sum2 = sum + background[i + 1][j + 1];
					if (max_value < sum2) max_value = sum2;
				}
			}

			// ㅁ         ㅁ
			// ㅁㅁ and ㅁㅁ
			// ㅁ         ㅁ
			if (i + 2 < n) {
				int sum = background[i][j] + background[i + 1][j] + background[i + 2][j];
				if (j + 1 < m) {
					int sum2 = sum + background[i + 1][j + 1];
					if (max_value < sum2) max_value = sum2;
				}
				if (j - 1 >= 0) {
					int sum2 = sum + background[i + 1][j - 1];
					if (max_value < sum2) max_value = sum2;
				}
			}

			// ㅁㅁ
			// ㅁㅁ
			if (i + 1 < n && j + 1 < m) {
				int sum = background[i][j] + background[i][j + 1] + background[i + 1][j] + background[i + 1][j + 1];
				if (max_value < sum) max_value = sum;
			}
		}
	}

	cout << max_value;
}

int main(void) {
	Solution14500();
	return 0;
}