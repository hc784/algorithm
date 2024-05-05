#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int k;
    cin >> k;

    const int INF = INT_MAX;

    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> distance(n + 1, INF);

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }

    auto dijkstra = [&graph, &distance](int start) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push(make_pair(0, start));
        distance[start] = 0;

        while (!q.empty()) {
            int dist = q.top().first;
            int now = q.top().second;
            q.pop();

            if (distance[now] < dist) {
                continue;
            }

            for (const auto& edge : graph[now]) {
                int cost = dist + edge.second;
                if (cost < distance[edge.first]) {
                    distance[edge.first] = cost;
                    q.push(make_pair(cost, edge.first));
                }
            }
        }
    };

    dijkstra(k);

    for (int i = 1; i <= n; ++i) {
        if (distance[i] == INF) {
            cout << "INF" << "\n";
        } else {
            cout << distance[i] << "\n";
        }
    }

    return 0;
}