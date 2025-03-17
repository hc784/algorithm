#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int score[20][20], minVal = 987654321, n;
/*
재귀로 팀나누기.
n/2 만족할때까지 팀 하나 나누고 나눈 팀 점수 계산하기.
팀 안정해진 나머지도 계산하기.

팀 나누기
for + 재귀.
한명 정해질때마다 재귀 들어가기.
매개변수에 팀원 수 넣고, 기저조건 팀원 수 == n/2

기저조건 만족시에 정해진 팀 각각 점수 계산.

전역변수로 가장 작은 점수 min 값 저장.

팀을 매개변수로? 전역변수로 나눌지?


*/

void calScore(bool team[20]) {
	int team1 = 0, team2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (team[i] && team[j]) {
				team1 += score[i][j] ;
			}
			else if (!team[i] && !team[j]) {
				team2 += score[i][j] ;
			}
		}
		
	}
	int sco = abs(team1 - team2);
	minVal = min(minVal, sco);
}

void dfs(int start ,int teamNum, bool team[20]) {
	if (n / 2 == teamNum) {
		calScore(team);
	}

	for (int i = start; i < n; i++) {
		team[i] = true;
		dfs(i+1,teamNum+1, team);
		team[i] = false;
	}
	

}

int main() {


	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> score[i][j];
		}
	}
	bool team[20] = { false, };
	dfs(0, 0, team);
	cout << minVal;
	return 0;

}