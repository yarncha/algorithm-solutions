#include <iostream>
#include <cmath>
#include <string>
using namespace std;
const int kMaxValueOfCharacters = 25;

// 목표 : input_base진법의 수가 주어지고, 이를 output_base진법으로 바꾸어 출력한다
// (이때 한 자리씩 공백 기준으로 출력)

void Solution11576() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int input_base, output_base;		// 바꿀 수의 진법과 바꿀 진법이 주어짐
	cin >> input_base >> output_base;

	// 1. 먼저 input_base진법의 수를 읽어들여 배열의 끝에서부터 저장-----------------------------------------------------------------------------
	// 1 2 3과 같이 주어진다고 하면 배열에는 00....00123이렇게 저장되어있음
	int num_of_number_character;		// 주어진 수의 자릿수 개수
	cin >> num_of_number_character;
	int input_number_array[kMaxValueOfCharacters] = { 0, };			// 바꿀 수가 주어지면 각각의 자릿수를 저장할 배열
	for (int i = kMaxValueOfCharacters - num_of_number_character; i < kMaxValueOfCharacters; i++)
	{
		// 높은 자리수부터 차례차례 주어짐. 이를 배열의 끝-주어진 수 개수에서부터 저장
		int input_number;
		cin >> input_number;
		input_number_array[i] = input_number;
	}

	// 2. 이제 값을 저장했으면 10진수로 변환-----------------------------------------------------------------------------------------------------
	int value_of_decimal = 0;	// 변환한 10진수 값
	int val_of_pows = 0;
	for (int j = kMaxValueOfCharacters - 1; j >= kMaxValueOfCharacters - num_of_number_character; j--)
	{
		int value_of_char = input_number_array[j];
		value_of_decimal += pow(input_base, val_of_pows) * value_of_char;
		val_of_pows++;
	}

	// 3. 10진수로 변환된 수를 다시 output_base진법의 수로 변환----------------------------------------------------------------------------------
	if (value_of_decimal == 0) {
		// 입력받은 10진법 수가 0일 경우 처리
		cout << "0";
		return;
	}

	string value_of_result = "";
	while (value_of_decimal >= output_base) {
		int result_of_mod = value_of_decimal % output_base;
		value_of_result.insert(0, " " + to_string(result_of_mod));
		value_of_decimal = value_of_decimal / output_base;
	}
	value_of_result.insert(0, to_string(value_of_decimal));

	cout << value_of_result;
}

int main(void) {
	Solution11576();
	return 0;
}
