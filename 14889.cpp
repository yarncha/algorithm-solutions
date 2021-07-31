#include <iostream>
using namespace std;

/*
백트래킹에 대해서 배우면서 풀어본 문제. 재귀함수를 이용해 브루트포스를 하다 보면 주어진 범위를 넘어간다던가 불가능한 경우가 생기는데, 이런 경우를 제외하고(리턴해버림) 브루트 포스를 진행하는 것을 백트래킹이라 한다.

이 문제 같은 경우에는 한 팀에 반 초과의 팀원이 들어갔을 겨우에는 반반 팀 성립이 안 되니까 이 경우에를 빼버렸음
*/

int capability_value[20][20];			// 각 팀원들의 능력치를 저장할 배열
int team_1[20];							// team1멤버을 저장할 배열
int team_2[20];							// team2멤버를 저장할 배열
int min_team_score_gap = -1;				// 두 팀의 최소 스코어 차이

void GetScoreGap(int half_num_people) {
	// 현재 구한 팀의 능력치 차이를 구하는 함수

	// 먼저 각 팀의 점수를 구한 뒤
	int team_1_score = 0;
	for (int i = 0; i < half_num_people; i++)
	{
		for (int j = i + 1; j < half_num_people; j++)
		{
			team_1_score += capability_value[team_1[i]][team_1[j]];
			team_1_score += capability_value[team_1[j]][team_1[i]];
		}
	}

	int team_2_score = 0;
	for (int i = 0; i < half_num_people; i++)
	{
		for (int j = i + 1; j < half_num_people; j++)
		{
			team_2_score += capability_value[team_2[i]][team_2[j]];
			team_2_score += capability_value[team_2[j]][team_2[i]];
		}
	}

	// 점수차를 구함
	int score_gap = team_1_score - team_2_score;
	if (score_gap < 0) {
		score_gap *= -1;
	}

	if (min_team_score_gap == -1 || min_team_score_gap > score_gap) {
		min_team_score_gap = score_gap;
	}

	return;
}

void GetTeamComposition(int cur_member, int team1_size, int team2_size, int half_num_people) {
	if (team1_size > half_num_people || team2_size > half_num_people) {
		// 현재 한쪽 팀이라도 반을 넘어간다면 답을 구할 수 없으니 리턴
		return;
	}

	if (cur_member == half_num_people * 2) {
		// 딱 원하던 팀 구성이 되었을 때는 답을 구해봄
		GetScoreGap(half_num_people);
		return;
	}

	// 현재 멤버(cur_member)에 대해서 답 구해보기
	team_1[team1_size++] = cur_member;
	GetTeamComposition(cur_member + 1, team1_size, team2_size, half_num_people);

	team1_size--;
	team_2[team2_size++] = cur_member;
	GetTeamComposition(cur_member + 1, team1_size, team2_size, half_num_people);

	return;
}

void Solution14889() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// 입력받기
	int num_people;
	cin >> num_people;

	for (int i = 0; i < num_people; i++)
	{
		for (int j = 0; j < num_people; j++)
		{
			cin >> capability_value[i][j];
		}
	}

	GetTeamComposition(0, 0, 0, num_people / 2);

	cout << min_team_score_gap << "\n";
}

int main(void) {
	Solution14889();
	return 0;
}