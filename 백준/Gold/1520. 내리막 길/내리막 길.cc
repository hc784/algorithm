#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int map[500][500];
int cache[500][500];
int m, n;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = {0, 1, 0, -1};

int dp(int x,int y) {
	if (x == m - 1 && y == n - 1)
		return 1;

	int& ret = cache[x][y];

	if (ret != -1)
		return ret;

	ret = 0; 

	for (int i = 0; i < 4; i++) {
		if (x + dx[i] < 0 || x + dx[i] >= m || y + dy[i] < 0 || y + dy[i] >= n) continue;
		if (map[x + dx[i]][y + dy[i]] < map[x][y]) {
				ret += dp(x + dx[i], y + dy[i]);
		}
	}

	return ret;

}
int main() {

	cin >> m >> n;

	memset(cache, -1, sizeof(cache));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	cout << dp(0, 0);

	return 0;

}