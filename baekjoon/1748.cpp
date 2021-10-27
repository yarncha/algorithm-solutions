#include <iostream>
#include <cmath>
using namespace std;

/*
수의 자릿수별로 나누어서 계산이 가능함
1부터 N까지 수가 빠짐없이 있기 때문에
*/

void Solution1748() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num;			// 1~num까지의 수를 이어쓰기 위한 수 (1~100 000 000)
	cin >> num;

	int base = 1;		// 현재 구할 수의 자릿수
	int result = 0;		// 1~num까지의 수를 이어썼을 때의 수의 자릿수
	while (true)
	{
		if (pow(10, base) - 1 < num) {
			result += base * 9 * pow(10, base - 1);
			base++;
		}
		else {
			result += base * (num - pow(10, base - 1) + 1);
			break;
		}
	}

	cout << result;
}

int main(void) {
	Solution1748();
	return 0;
}