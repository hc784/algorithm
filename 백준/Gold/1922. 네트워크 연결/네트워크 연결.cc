#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <functional>
using namespace std;
const int INF = 2000000000;
int n, m;
vector <pair<int, int>> vec[1001];
vector <pair<int, int>> selected;
bool visited[1001] = { 0, };

int result = 0;
void prim() {

	priority_queue <pair<int, int>> pq;
	for (int i = 0; i < vec[1].size(); i++) {
		int to = vec[1][i].first;
		int co = vec[1][i].second;
		pq.push(make_pair(-1 * co, to));
	}

	visited[1] = 1;
	while (!pq.empty()) {
		int co = pq.top().first * -1;
		int to = pq.top().second;
		pq.pop();

		if (visited[to] == false) {

			visited[to] = true;
			result += co;

			for (int i = 0; i < vec[to].size(); i++) {
				int nto = vec[to][i].first;
				int nco = vec[to][i].second;

				if(visited[nto] == false)
					pq.push(make_pair(-1 * nco, nto));
			}
		}



	}

}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	cin >> m;

	int from, to, cost;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> cost;
		vec[from].push_back(make_pair(to, cost));
		vec[to].push_back(make_pair(from, cost));
	}

	prim();
	
	cout << result << endl;

	return 0;
}