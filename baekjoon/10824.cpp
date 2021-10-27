#include <iostream>
#include <cmath>
using namespace std;

void solution_10824() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	//방법 1 : b와 d의 자리수를 구해서 그 수를 곱한 후 덧셈을 해 주는 방식
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	// b와 d의 자리수를 구한다.
	int num_of_10_b = log10(b) + 1;
	int num_of_10_d = log10(d) + 1;

	// 자리수에 따라 a를 계산해서 ab를 붙여 준다
	long long number_ab = (a * pow(10, num_of_10_b)) + b;
	long long number_cd = (c * pow(10, num_of_10_d)) + d;

	//더하고 출력
	cout << number_ab + number_cd;
}

int main(void) {
	solution_10824();
	return 0;
}