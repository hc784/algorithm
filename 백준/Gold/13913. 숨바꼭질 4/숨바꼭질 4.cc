#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
int start, dest, dist[100001], prePosition[100001] ;
bool visited[100001] = { false, };
/*
dist에는 해당 위치까지 도달하는데 걸린 시간을 저장 해야하나?
이미 방문햇으면 그냥 return 하면 되는거 아닌가?
앞에서 이미 방문했으면? 이미 시간이 같거나 큰 경우.
거리는 저장할 필요없음.
그냥 return 하면 될듯.

다시 만들려면?
dist에는 이전 위치를 저장한다? 차례대로 따라가기?
방문한 경우에는 그냥 return 할거니까 상관없고.
이미 방문 된 경우에는 이미 그 뒤로는 실행된 상태.

첫 방문 시에는 이전 인덱스를 저장.


시간은 어떻게 구하는지?

dist에 현재 시간을 저장해야하나?
depth를 저장해야하네.

최단거리를 구해야하기 때문에.


*/
void bfs() {
	// *2 or +1 or -1
	queue<int> q;
	q.push(start);
	visited[start] = true;
	dist[start] = 0;
	while (!q.empty()) {
		int dis = q.front();
		q.pop();

		int next[3] = { dis - 1 , dis + 1 , dis * 2 };

		for (int i = 0; i < 3; i++) {
			if (0 <= next[i] && next[i] <= 100000 && !visited[next[i]]) {
				if (next[i] != dis - 1 && dis > dest)
					continue;

				prePosition[next[i]] = dis;
				visited[next[i]] = true;
				q.push(next[i]);
				dist[next[i]] = dist[dis] + 1;

				if (next[i] == dest) return;
			}
		}


	}
	
}

int main() {
	cin >> start>>dest;
	memset(dist, -1, sizeof(dist));
	memset(prePosition, -1, sizeof(prePosition));

	bfs();
	cout << dist[dest] << endl;
	
	stack<int> ret;
	int i = dest;
	while (i != -1) {
		ret.push(i);
		i = prePosition[i];
	}
	while (!ret.empty()) {
		cout << ret.top()<<" ";
		ret.pop();
	}
		
	return 0;

}