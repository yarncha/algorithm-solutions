#include <iostream>
using namespace std;

int capability_value[20][20];			// 각 팀원들의 능력치를 저장할 배열
int team_1[20];							// team1멤버을 저장할 배열
int team_2[20];							// team2멤버를 저장할 배열
int min_team_score_gap = -1;				// 두 팀의 최소 스코어 차이

void GetScoreGap(int team1_size, int team2_size) {
	// 현재 구한 팀의 능력치 차이를 구하는 함수

	// 먼저 각 팀의 점수를 구한 뒤
	int team_1_score = 0;
	for (int i = 0; i < team1_size; i++)
	{
		for (int j = i + 1; j < team1_size; j++)
		{
			team_1_score += capability_value[team_1[i]][team_1[j]];
			team_1_score += capability_value[team_1[j]][team_1[i]];
		}
	}

	int team_2_score = 0;
	for (int i = 0; i < team2_size; i++)
	{
		for (int j = i + 1; j < team2_size; j++)
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

void GetTeamComposition(int cur_member, int team1_size, int team2_size, int num_people) {
	if (team1_size >= num_people || team2_size >= num_people) {
		// 한쪽 팀에 모든 인원이 쏠렸을 때는 답을 구할 수 없으니 리턴
		return;
	}

	if (cur_member == num_people) {
		// 딱 원하던 팀 구성이 되었을 때는 답을 구해봄
		GetScoreGap(team1_size, team2_size);
		return;
	}

	// 현재 멤버(cur_member)에 대해서 답 구해보기
	team_1[team1_size++] = cur_member;
	GetTeamComposition(cur_member + 1, team1_size, team2_size, num_people);

	team1_size--;
	team_2[team2_size++] = cur_member;
	GetTeamComposition(cur_member + 1, team1_size, team2_size, num_people);

	return;
}

void Solution15661() {
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

	GetTeamComposition(0, 0, 0, num_people);

	cout << min_team_score_gap << "\n";
}

int main(void) {
	Solution15661();
	return 0;
}