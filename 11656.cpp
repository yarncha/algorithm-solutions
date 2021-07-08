#include <iostream>
#include <string>
using namespace std;

int CompareTwoIndex(int a_index, int b_index, string input_string) {
	// index값과 문자열을 넣으면, input_string에서 a인덱스에 있는 문자와 b인덱스에 있는 문자 중
	// 어떤 글자로 시작하는 접미사가 더 작은지 알려줌 (a<z), (a<ab)
	// input_string.at(a_index)로 시작하는 접미사가 더 작을 경우 0, b_index가 더 작을 경우 1
	// 단, 우선순위가 같은 것이 나올 수 없으므로 처리하지 않음

	if (input_string.at(a_index) < input_string.at(b_index)) {
		// ex) a<z
		return 0;
	}
	else if (input_string.at(b_index) < input_string.at(a_index)) {
		return 1;
	}
	else {
		// 같을 경우 다음 값을 비교
		if (input_string.size() <= (a_index + 1) || input_string.size() <= (b_index + 1)) {
			// 둘 중 하나가 다음 원소가 없는 경우는 그 없는 것이 더 작은 것 ex) a<ab
			if (a_index > b_index) {
				return 0;
			}
			else {
				return 1;
			}
		}
		else {
			return CompareTwoIndex(a_index + 1, b_index + 1, input_string);
		}
	}
}

void QuickSort(int start_index, int end_index, int* array, string input_string) {
	// 퀵소트, start_index부터 end_index까지 퀵소트를 이용하여 정렬한다
	if (start_index >= end_index) {
		//종료조건 : 하나의 원소를 가졌을 때, 더 이상 정렬할 것이 없으므로 종료한다
		return;
	}

	int pivot_index = start_index;
	int left_index = start_index + 1;
	int right_index = end_index;

	while (left_index <= right_index) {
		while ((left_index <= end_index) && CompareTwoIndex(array[pivot_index], array[left_index], input_string)) {
			//왼쪽부터 pivot보다 큰 값이 나올때까지 이동 (pivot<left일때까지)
			left_index++;
		}

		while ((right_index >= (start_index + 1)) && CompareTwoIndex(array[right_index], array[pivot_index], input_string)) {
			//오른쪽부터 pivot보다 작은 값이 나올때까지 이동 (right<pivot일때까지)
			right_index--;
		}

		if (left_index <= right_index) {
			int temp_value = array[left_index];
			array[left_index] = array[right_index];
			array[right_index] = temp_value;
		}
	}

	// left와 right가 엇갈린 상태, pivot의 위치를 left의 위치와 바꿔주고 pivot의 위치는 픽스됨
	int temp_value_2 = array[right_index];
	array[right_index] = array[pivot_index];
	array[pivot_index] = temp_value_2;

	// pivot의 양 옆을 재귀적으로 정렬
	QuickSort(start_index, right_index - 1, array, input_string);
	QuickSort(right_index + 1, end_index, array, input_string);

	return;
}

void Solution11656() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string input;	// 입력한 문자열 S
	getline(cin, input);

	int first_input_size = input.size();
	int index_array[1000];	// 접미사 순서를 저장할 배열 index_array. 처음에는 0, 1, 2, 3... 으로 초기화함
	for (int j = 0; j < input.size(); j++)
	{
		index_array[j] = j;
	}

	// 퀵소트를 이용해 index_array를 정렬
	QuickSort(0, first_input_size - 1, index_array, input);

	// 접미사 순서를 저장해둔 index_array에 따라 출력.
	// 정렬된 index_array는 어떤 접미사를 출력해야 하는지 배열이 순서대로 정렬되어 있음
	for (int k = 0; k < first_input_size; k++)
	{
		cout << input.substr(index_array[k]) << "\n";
	}
}

int main(void) {
	Solution11656();
	return 0;
}