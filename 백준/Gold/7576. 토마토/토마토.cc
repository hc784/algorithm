#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<bool> visited;
//vector<vector<int>> map;
int map[1000][1000];
int cnt = 0;
vector<int> ret;
int n, m;

int a1[4] = { 0,1,-1,0 };
int a2[4] = { 1,0,0,-1 };

bool test() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j]<<" ";
			}
		cout << endl;
		}
	}

int main() {

	cin >> m >> n;
	queue<pair<int, int>> q;
	 //vector<vector<int>>(n,vector<int>(m));

	 int popNum = 0;
	 int savePushNum = 0;
	 int pushNum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
			{
				q.push(pair<int, int>(i, j));
				savePushNum++;
			}
				

		}
	}
	if (test()) {
		cout << 0;
		return 0;
	}
	int cnt = 0;
	while (!q.empty()) {
		
		pair<int, int> temp = q.front();
		q.pop();
		popNum++;

		for (int i = 0; i < 4; i++)
		{
			int n1 = temp.first + a1[i];
			int n2 = temp.second + a2[i];
			if (n1<0 || n1>=n || n2<0 || n2 >= m)
				continue;
			int& th = map[n1][n2];
			if (th == 0)
			{
				th = 1;
				q.push(pair<int,int>(n1,n2));
				pushNum++;
			}
				
			
		}

		if (popNum == savePushNum) {
			cnt++;
			popNum = 0;
			savePushNum = pushNum;
			pushNum = 0;
		}


	}

	if (test())
		cout << cnt-1;
	else
		cout << -1;
	return 0;

}