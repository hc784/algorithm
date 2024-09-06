#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int map[100005], cache[100005][5][5],power[5][5],minV=987654321;



int dp(int idx, int a, int b) {
	
	if ((a != 0 && b != 0) && a == b)
		return 987654321;
	if (map[idx] == 0)
	{
		return 0;
	}
	int& ret = cache[idx][a][b];
	if (ret != -1) {
		return  ret;
	}



	return ret= min(dp(idx + 1, map[idx], b) + power[a][map[idx]], dp(idx + 1, a, map[idx])+ power[b][map[idx]]);
	
}
int main() {
	//0에서 이동 2
	//같은 곳 1
	//인접 3
	// 반대 4
	//시작은 두발다 0. 한발이 움직이는 경우, 두발다 움직이는 경우. cache로 최솟값을 저장.
	// 뺏을 때 절대값이 2면 반대 4
	// 시작은 2 고정

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == 0)
				power[i][j] = 2; 
			else if (abs(i - j) == 2)
				power[i][j] = 4;
			else if (i == j)
				power[i][j] = 1;
			else
				power[i][j] = 3;

		}
	}

	//for (int i = 0; i < 5; i++) {
	//	for (int j = 0; j < 5; j++) {
	//		cout << power[i][j]<<" ";
	//	}
	//	cout << endl;
	//}
	
	map[0] = -1;
	for (int i = 1; map[	i-1] != 0; i++)
		scanf("%d", &map[i]);

	int f = 2;
	int a=map[1], b=0;
	memset(cache,-1, sizeof(cache));
	
	// a가 움직이는 경우 b 가 움직이는 경우
	// 수열의 위치 idx cache[idx]보다 힘이 더 크다면 return

	cout << dp(2, a, b)+2;

	return 0;

}