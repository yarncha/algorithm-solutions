#include <iostream>
using namespace std;

// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 목표 : 현재 위치 current_position, 거쳐야 할 point들이 주어지고,
// 이 점들을 모두 거치기 위한 가장 큰 이동 거리 D를 찾기
// 현재 위치에서 -D, D만큼 이동할 수 있기 때문에 현재 위치와 point간의 거리를 모두 측정해본 후,
// 이 거리가 모두 D의 배수이면 된다. 즉 모든 거리의 최대공약수를 구하는 문제
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

// 최대공약수를 구하는 공식
// 시간 복잡도 O(log(n+m))
int gcd(int x, int y) {
	while (y > 0)
	{
		int mod_value = x % y;
		x = y, y = mod_value;
	}
	return x;
}

void Solution17087() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int num_of_points, current_position;	// 점의 개수와 현재 위치 (각각 최대 100,000/ 최대 1,000,000,000)
	cin >> num_of_points >> current_position;

	int distance[100000];	// 현재 위치와 점들과의 거리 차이를 저장할 배열
	int position_of_point;
	for (int i = 0; i < num_of_points; i++)
	{
		cin >> position_of_point;
		int temp = current_position - position_of_point;
		if (temp < 0) {
			temp = temp * (-1);
		}
		distance[i] = temp;
	}

	// distance에 저장된 모든 거리 차이의 최대공약수를 구한다.
	int gcd_value = distance[0];
	for (int j = 1; j < num_of_points; j++)
	{
		// 최대공약수의 특징 상, gcd(a,gcd(b,c)) = gcd(gcd(a,b),c)이므로
		// 앞에서부터 두 개씩 최대공약수를 구해가면 된다
		gcd_value = gcd(gcd_value, distance[j]);
	}

	cout << gcd_value;
}

int main(void) {
	Solution17087();
	return 0;
}