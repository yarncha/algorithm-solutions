#include <iostream>
#include <string>
using namespace std;

void solution_10824() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	//방법 2 : 각각을 string을 이용해 더한 후, 숫자로 바꿔줘서 연산하는 형식
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	// a,b와 c,d를 각각 to_string함수를 이용해 string으로 만들어준 후 더해준다
	string string_of_ab = to_string(a) + to_string(b);
	string string_of_cd = to_string(c) + to_string(d);

	// 이를 stoll함수를 이용하여 string을 long long타입으로 변경
	long long number_ab = stoll(string_of_ab);
	long long number_cd = stoll(string_of_cd);

	//더하고 출력
	cout << number_ab + number_cd;
}

int main(void) {
	solution_10824();
	return 0;
}
