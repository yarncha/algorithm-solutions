#include <iostream>
#include <algorithm>
using namespace std;

void Solution2309() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int height[9];					// 9명 난쟁이들의 각각 키
	int sum_of_height = 0;			// 9명 난쟁이들의 키의 총 합
	for (int i = 0; i < 9; i++)
	{
		//각각의 키를 받아서 입력하고, 합도 구함
		cin >> height[i];
		sum_of_height += height[i];
	}

	// 이제 여기서 2명씩 키의 합을 구하고 총 합에서 빼 본다
	// 만약 총 합에서 뺐을 때 100이 되는 키가 있다면 그 둘이 일곱 난쟁이가 아닌 것
	for (int j = 0; j < 9; j++)
	{
		for (int k = j + 1; k < 9; k++)
		{
			if (sum_of_height - height[j] - height[k] == 100) {
				height[k] = height[8];
				height[j] = height[7];
				sort(height, height + 7);
				for (int m = 0; m < 7; m++)
				{
					cout << height[m] << "\n";
				}
				return;
			}
		}
	}

	return;
}

int main(void) {
	Solution2309();
	return 0;
}