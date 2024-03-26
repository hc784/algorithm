#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;
int n, m;
int visited[102][102];

int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };

int map[102][102];




void bfs(int x, int y) {
	queue<tuple<int, int, int>> q;
	visited[x][y] = true;
	/*cout << x << "," << y << endl;*/
	q.push(tuple<int, int, int>(x, y, 1));

	while (!q.empty()) {
		tuple<int, int,int> here = q.front();

		for (int i = 0; i < 4; i++)
		{
			int newX = get<0>(here) + dx[i];
			int newY = get<1>(here) + dy[i];
			

			if (map[newX][newY] && !visited[newX][newY])
			{
				//cout << newX << "," << newY << endl;
				visited[newX][newY] = 1;
				q.push(tuple<int, int,int>(newX, newY, get<2>(here)+1));
				if (newX == n && newY == m)
					cout <<  get<2>(here) +1 << endl;
			}

		}
		q.pop();

	}

}


int main() {
	
		cin >> n >> m;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));

		
		

		for (int i = 1; i <= n; i++)
		{
			string str;
			cin >> str;
			for (int j = 0; j < m; j++) {
				map[i][j+1] = (int)(str[j] - '0');
				
			}
		}

		/*for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				cout << map[i][j];
			}
			cout << endl;
		}*/

		bfs(1, 1);
		return 0;
	}
