#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
* 1. 그래프 입력 받기.
* 2. 시작점 정하기.
* 3. 시작점에서 bfs 돌리기.
* 4. 두 그룹으로 나누는데, bool로 나누면 될듯.
* 5. visited는 표시해야하나?
* 6. 시작점은 false 시작점에서 도착하는 부분은 true
* 7. 전부 돌아야하나? bfs는 시작점을 체크해야하네 시작점으로 visted 됐는지 체크하기.
* 8. bfs 한 번 돌때 시작점이랑 도착점의 그룹이 같을 경우에는 이분 그래프가 아니고, 모두 만족시에는 이분 그래프이다.
* 9. 비연결 그래프도 고려해야하는지?
* 10. 이차원 배열로 받을지, vector로 받을지.
* 
* group 나누기. 
*/
bool visited[20002] = { false, }, group[20002];

bool bfs(int start, vector<vector<int>>& graph) {

	queue<int> q;
	q.push(start);
	visited[start] = true; 
	group[start] = false;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int a : graph[node]) {
			
			if (visited[a] == false) { // 이미 방문한경우에 연결된경우.다른색인지 확인.
				group[a] = !group[node];
				visited[a] = true;
				q.push(a);
			}

			else
			{
				if (group[a] == group[node]) {
					return false;
				}
			}
		}

	}
	return true;
}

int main() {

	int tc;
	cin >> tc;
	while (tc--) {
		
		int v, e;
		cin >> v >> e;

		for (int i = 0; i <= v; i++) {
			visited[i] = false;
		}
		vector<vector<int>> graph(v + 1);
		for (int i = 0; i < e; i++)
		{
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);

		}
		bool ret = true;
		for (int i = 1; i <= v; i++) {
			if (!visited[i]&&!graph[i].empty()) {
				if (!bfs(i, graph)) {
					cout << "NO"<<endl;
					ret = false;
					break;
				}
			}
		}
		if (ret) cout << "YES" << endl;


	}
	




	//for(int i = 0 ; i<v;i++)
	//for (vector<int> a : graph) {
	//	for (int b : a) {
	//		cout << b << endl;
	//	}

	//}
	return 0;
}