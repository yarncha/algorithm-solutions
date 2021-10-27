/*
모든 경우의 수를 다 해보기에는 시간이너무 오래 걸림
x값을 고정하고, y값에 대해서만 해 보면 O(n)의 시간이 걸림
*/

#include <iostream>
using namespace std;

void Solution6064() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_testcase;
	cin >> num_testcase;

	for (int i = 0; i < num_testcase; i++)
	{
		int result = 0;

		int M, N, x, y;		// M,N은 1~40000
		cin >> M >> N >> x >> y;

		// 나머지를 사용하기 위해 빼줌
		x--;
		y--;

		for (int j = x; j < M * N; j += M)
		{
			// j를 x부터 시작하고, M만큼 늘려주면 j%M의 값은 항상 x값이 됨. 그래서 x는 고려하지 않아도 되고, 주어진 범위 전까지 해당하는 y가 나오는지 확인하면 됨
			if (j % N == y) {
				result = j + 2;
				break;
			}
		}

		cout << result - 1 << "\n";
	}

	return;
}

int main(void) {
	Solution6064();
	return 0;
}