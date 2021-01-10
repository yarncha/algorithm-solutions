#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int input_command;
	cin >> input_command;

	int a, b, gcd_value;

	for (int i = 0; i < input_command; i++)
	{
		cin >> a >> b;
		gcd_value = gcd(a, b);
		cout << gcd_value * (a / gcd_value) * (b / gcd_value) << "\n";
	}

	return 0;
}