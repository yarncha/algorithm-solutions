#include <iostream>
using namespace std;

bool is_valid_number(int input_number, int* buttons) {
	if (input_number == 0) {
		if (buttons[0] == -1) {
			return false;
		}
	}
	while (input_number > 0) {
		if (buttons[input_number % 10] == -1) {
			return false;
		}
		input_number /= 10;
	}
	return true;
}

void Solution1107() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 1. 이동하려고 하는 채널과, 고장난 버튼을 입력받음
	int destination;		// 이동하려는 채널
	cin >> destination;

	int button[10] = { 0,1,2,3,4,5,6,7,8,9 };		// 리모콘의 버튼 배열
	int num_of_button = 10;							// 쓸 수 있는 버튼의 개수
	int num_of_not_working_buttons;
	cin >> num_of_not_working_buttons;
	for (int i = 0; i < num_of_not_working_buttons; i++)
	{
		// 쓸 수 없는 버튼들을 하나씩 입력받으면서 쓸 수 없는 건 -1로 채워줌
		int temp;
		cin >> temp;
		button[temp] = -1;
		num_of_button--;
	}

	// 2. 100부터 목적지까지 거리를 초기값으로 지정해두고, 아무 버튼도 쓸 수 없을 때의 처리를 해줌
	int total_move_to_destination = 100 - destination;			// 나중에 출력해줄 답. 초기값은 100에서 목적지까지 +나 -버튼만 눌러서 이동하는 횟수임
	if (total_move_to_destination < 0) {
		total_move_to_destination = total_move_to_destination * (-1);
	}

	if (num_of_button == 0) {
		// 모든 버튼이 쓸 수 없을 경우는 그냥 초기값 total_move_to_destination으로 끝임
		cout << total_move_to_destination;
		return;
	}

	// 3. 쓸 수 있는 버튼으로 자리수 늘려가며 전부 검사
	// 먼저 destination의 범위를 구함. 그 주변만 검사하면 될 것 같은데...!!
	int digit = 0;		//destination의 자릿수
	for (int i = destination; i >= 1; i = i / 10)
	{
		digit++;
	}

	int start, end;
	if (digit < 3) {
		// 이동하려는 채널이 0이거나, 자릿수가 1자리 2자리일 경우 (0~99)
		start = 0;
		end = 1000;
	}
	else {
		start = 10;
		end = 9999;
		for (int i = 0; i < digit - 3; i++)
		{
			start *= 10;
			end = end * 10 + 9;
		}
	}

	for (int current_location = start; current_location < end; current_location++)
	{
		// 쓸 수 있는 버튼으로 만들어졌나 먼저 검사
		if (is_valid_number(current_location, button)) {
			// 쓸 수 있는 버튼인게 확인된 경우, 절댓값 계산해서 total...이랑 비교 후 이게 더작을경우 업뎃
			int distance = destination - current_location;
			if (distance < 0) {
				distance = distance * (-1);
			}
			if (current_location == 0) {
				distance++;
			}
			else {
				for (int m = current_location; m >= 1; m = m / 10)
				{
					distance++;
				}
			}

			if (total_move_to_destination > distance) {
				total_move_to_destination = distance;
			}
		}
	}

	cout << total_move_to_destination;
}

int main(void) {
	Solution1107();
	return 0;
}