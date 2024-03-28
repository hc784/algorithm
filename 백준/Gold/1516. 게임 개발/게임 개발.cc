#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
vector<vector<int>> gra;
int dp[500],n, indegree[500] , useTime[500], result =0;
void bfs() {
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int here = q.front();
                    
       // cout << here << endl;
        for (int i = 0; i < gra[here].size(); i++) {
            int next = gra[here][i];
            dp[next] = max(dp[next], dp[here] + useTime[next]);

           // cout << next << endl;
            result = max(result, dp[next]);
            if (--indegree[next] == 0)
            {
                q.push(next);
            }
        }
        q.pop();
    }

}

int main()
{
    cin >> n; 


    gra = vector<vector<int>>(n+1,vector<int>());
    for (int i = 0; i < n; i++) {
        cin >> useTime[i];
        dp[i] = useTime[i];
        int temp;
        cin >> temp;
        int num = 0;
        while (temp != -1)
        {
            num++;
            gra[temp -1 ].push_back(i);
            cin >> temp;
        }
        indegree[i] = num;

    }
    //for (int i = 0; i <gra.size();i++) {
    //    cout << i << " :  ";
    //    for (auto b : gra[i])
    //        cout << b << " ";
    //    cout << endl;
    //}
    //for (auto a : indegree)
    //    cout << a << " ";
    bfs();
    for (int i = 0; i < n; i++) {
        cout << dp[i] << endl;
    }

    return 0;
}