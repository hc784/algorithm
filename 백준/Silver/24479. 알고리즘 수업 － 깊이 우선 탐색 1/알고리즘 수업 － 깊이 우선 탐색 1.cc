#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<bool> visited;
vector<vector<int>> node;
int cnt = 0;
vector<int> ret;
void dfs(int r) {
	

	visited[r] = true;
	cnt++;
	ret[r] = cnt;
	
	for (int i = 0; i < node[r].size(); i++)
	{
		if (visited[node[r][i]] == false)
		{
			dfs(node[r][i]);
		}
			
	}

}
int main() {
	int n, m, r;
	cin >> n >> m >> r;

	 node = vector<vector<int>>(n+1);
	 ret = vector<int>(n+1);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d", &a);
		scanf("%d", &b);
		node[a].push_back(b);
		node[b].push_back(a);
	}
	visited = vector<bool>(node.size(), false);
	for (int i = 0; i < node.size(); i++) {
		sort(node[i].begin(), node[i].end());
	}
	dfs(r);
	
	bool ok= true;
	for (int i = 1; i <= n; i++) {
		printf("%d\n",ret[i]);
	}

	return 0;

}