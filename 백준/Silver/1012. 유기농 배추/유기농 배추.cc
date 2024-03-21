#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>



using namespace std;
int n, m, k;
vector<bool> visited;

vector<vector<int>> gra,map;


void dfs(int here) {
	
	visited[here] = true;
//	cout << here << " ";

	for (int i = 0; i < gra[here].size(); i++)
	{
		if (!visited[gra[here][i]])
		{
			dfs(gra[here][i]);
		}
	}
}


int alldfs() {
	int num = 0;
	for (int i = 1; i <= k; i++) {
		if (!visited[i])
		{
			dfs(i);
			num++;
		}
			
	}
	
	return num;
}

int main() {
	// m 가로 n 세로 k 개수배추 
	// 인접한 배추 = 연결된 그래프 2차원에 저장하고 배열만들기
	int tc; 
	cin >> tc;
	while (tc--)
	{
		cin >> m >> n >> k;
		map = vector<vector<int>>(n + 3, vector<int>(m + 3, 0));
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> y >> x;
			map[x + 1][y + 1] = i + 1; // 1번 ~ k번
		}


		gra = vector<vector<int>>(k + 2, vector<int>(0));
		visited = vector<bool>(k + 2, false);
		vector<pair<int, int>> a = { {0,1}, {1,0} , {-1,0}, {0,-1} };
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++) {

				if (map[i][j])
				{
					for (int vec = 0; vec < 4; vec++)
					{
						int x = i + a[vec].first;
						int y = j + a[vec].second;
						if (map[x][y]) // i-1,j i+1,j / i,j+1
						{
							gra[map[i][j]].push_back(map[x][y]); //  gra[1~k].push 
						}
					}
				}

			}
		}

		cout << alldfs() << endl;
	}

	//for (int i = 0; i < map.size(); i++) {
	//	for (int j = 0; j < map[i].size(); j++) {
	//		cout << map[i][j]<<" ";
	//	}
	//	cout << endl;
	//}
	//
	//for (int i = 1 ; i<gra.size();i++)
	//{
	//	cout << i << " :: ";
	//	for (int j = 0 ; j < gra[i].size() ; j++) 
	//	{
	//		cout << gra[i][j] << " ";
	//	}
	//	cout << endl;
	//}
		
	return 0;
}