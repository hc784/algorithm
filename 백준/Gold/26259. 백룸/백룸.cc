#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n, m, map[1000][1000], cache[1000][1000];
bool iswall = true, equalX ;
pair<int, int> wall[2];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int dp(int y, int x) {
	
	if (y >= n || x >= m) return -987654321;
	

	if (y == n - 1 && x == m - 1)
		return map[y][x];
	
	int& ret = cache[y][x];
	if (ret != -1)
		return ret;	
	ret = 0;

	if (iswall && equalX && y >= wall[0].second && y < wall[1].second && x == wall[0].first - 1)
	{
		return ret = dp(y + 1, x) + map[y][x];

	}
		else if (iswall && !equalX && x >= wall[0].first && x < wall[1].first && wall[0].second - 1 == y)
		return ret = dp(y, x+1) + map[y][x];
	return ret = max(dp(y + 1 , x) + map[y][x] , dp(y, x + 1) + map[y][x]);
}

int main() {
	cin >> n >>m;
	memset(cache, -1, sizeof(cache));

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < 2; i++) {
		scanf("%d %d", &(wall[i].second), &(wall[i].first)); // first = x , second = y

	}
	if (wall[0].first == wall[1].first && wall[0].second == wall[1].second)
	{
		iswall = false;
	}
	else if (wall[0].first == wall[1].first) {
		equalX = true;
		if (wall[0].second > wall[1].second) {
			int temp = wall[0].second;
			wall[0].second = wall[1].second;
			wall[1].second = temp;
		}

	}

	else 
		if (wall[0].first > wall[1].first) {
			int temp = wall[0].first;
			wall[0].first = wall[1].first;
			wall[1].first = temp;
		equalX = false;
	}

	if (wall[0].first == 0 && wall[1].first >= m && iswall && wall[0].second>0 && wall[1].second<n) {
		cout << "Entity";
		return 0;
	}
	if (wall[0].second == 0 && wall[1].second == n &&iswall && wall[0].first >0 && wall[1].first <m) {
		cout << "Entity";
		return 0;
	}
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << map[i][j];
	//	}
	//	cout << endl;
	//}
	
	cout<<dp(0, 0);
	return 0;

}