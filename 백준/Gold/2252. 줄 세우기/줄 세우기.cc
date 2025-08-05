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

vector<vector<int>> graph(32001);
vector<int> sortedArray;
bool visited[32001] = { false, };
void dfs(int start) {
	
	for (int i = 0; i < graph[start].size(); i++) {
		
		if (!visited[graph[start][i]])
		{
			visited[graph[start][i]] = true;
			dfs(graph[start][i]);
		}
	}
	sortedArray.push_back(start);
	
	

}

int main() {
	int n, m;
	pair<int, int> diff[100000];
	
	
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i);

		}
			
	}

	
	for (int i = sortedArray.size() -1; i >=0; i--)
	{
		printf("%d ", sortedArray[i]);
	}

}

