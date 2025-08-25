#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <tuple>

using namespace std;

int graph[100001];
int visited[100001];
bool team[100001] = { false, };
int recurCnt, n;

void dfs(int start) {
		int& vist = visited[graph[start]];
		if (vist == -1)
		{
			visited[graph[start]] = recurCnt;
			dfs(graph[start]);
		}
		else if (vist == recurCnt && !team[graph[start]]) {
			team[graph[start]] = true;
			dfs(graph[start]);
		}
		else  {
			return;
		}
	
	

}

int main() {
	int tc;
	scanf("%d", &tc);

	while (tc--) {

		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &graph[i]);
		}

		memset(visited, -1, sizeof(visited));
		memset(team, 0, sizeof(team));

		recurCnt=0;
		for (int i = 1; i <= n; i++) {
			if (visited[i]==-1) {
				visited[i] = recurCnt;
				dfs(i);
				recurCnt++;
			}

		}

		int ret = 0;
		for (int i = 1; i <= n; i++) {
			if (!team[i])
				ret++;
		}
		printf("%d\n", ret);

	}
	
}


