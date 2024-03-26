#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>



using namespace std;
int n;
vector<int> usetime;
int time1[10000];
vector<vector<int>> gra;
vector<int> topological, indegree;


void bfs() {
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if(indegree[i]==0)
			q.push(i);
	}
	
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < gra[here].size(); i++)
		{
			int next = gra[here][i];
			usetime[next] = max(usetime[next], usetime[here] + time1[next]);
			if (--indegree[next] == 0)
			{
				q.push(next);
			}

		}
		
		

	}



}



int main() {
	cin >> n;
	gra = vector<vector<int>>(n, vector<int>(0));
	vector<int> time(n);
	indegree = vector<int>(n);
	usetime = vector<int>(n);
	topological = vector<int>(0);
	for (int i = 0; i < n; i++)
	{
		cin >> time1[i];
		usetime[i] = time1[i];
		cin >> indegree[i];
		for (int j = 0; j < indegree[i]; j++)
		{
			int node;
			cin >> node;
			gra[node - 1].push_back(i);
		}
	}

	bfs();
	cout << *max_element(usetime.begin(), usetime.end());
	
	return 0;
}