#include <iostream>
using namespace std;
int max_value[125251];			// i가 삼각형의 맨 위일 때 경로에 있는 가장 큰 값의 합
int triangle[125251];			// 삼각형의 각 원소들을 저장할 배열
int size_of_triangle;			// 입력받을 삼각형의 크기 1~500
int number_of_elements;			// 삼각형의 총 원소의 개수를 계산

int calculate_max_value(int current_index, int current_floor) {
	if (max_value[current_index] > -1) {
		// max_value에 이미 경로 최대값이 계산되어 저장되어 있을 때는 이를 그대로 리턴
		return max_value[current_index];
	}

	if (current_floor == size_of_triangle) {
		// 삼각형의 가장 아랫쪽에 있는 값들의 경우에는 max_value을 계산할 필요 없이 바로 값을 보내줌
		return triangle[current_index];
	}

	// current_index의 자식 둘 중 max_value이 더 큰 것을 선택하고 이에 triangle[current_index]를 더해준 값이
	// current_index까지의 경로상 가장 큰 값
	max_value[current_index] = max(calculate_max_value(current_index + current_floor, current_floor + 1), calculate_max_value(current_index + current_floor + 1, current_floor + 1)) + triangle[current_index];

	return max_value[current_index];
}

void Solution1932() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> size_of_triangle;
	number_of_elements = (size_of_triangle * (size_of_triangle + 1)) / 2;
	for (int i = 0; i < number_of_elements; i++)
	{
		// triangle에 각 원소들을 채워넣음
		int element;
		cin >> element;
		triangle[i] = element;

		// max_value도 미리 삼각형의 크기에 따라 -1로 채워줌
		max_value[i] = -1;
	}

	cout << calculate_max_value(0, 1);
}

int main(void) {
	Solution1932();
	return 0;
}
