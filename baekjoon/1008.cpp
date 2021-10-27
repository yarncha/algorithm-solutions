#include <iostream>
using namespace std;

void solution_1008() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// double로 입력을 받고
	double a, b;
	cin >> a >> b;

	//계산도 double로 한 후
	double result = a / b;

	// 소수점 아래 숫자를 10개로 해 두었음
	cout << fixed;
	cout.precision(10);
	cout << result;
}

int main(void) {
	solution_1008();
	return 0;
}