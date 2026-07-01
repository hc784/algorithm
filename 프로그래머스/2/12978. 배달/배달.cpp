#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
vector<vector<pair<int,int>> > gra(N+1);
    for(auto a : road){
        gra[a[0]].push_back({a[2],a[1]});   
        gra[a[1]].push_back({a[2],a[0]});
    }
    vector<int> dik(N+1,INF);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,1});
    dik[1]=0;
    while(!q.empty()){
        int time = q.top().first;
        int node = q.top().second;
        q.pop();
        if(time>dik[node]) continue;
        
        for(auto ss : gra[node]){
            int cost = ss.first+time;
            if(cost < dik[ss.second]){
                dik[ss.second]=cost;
                q.push({cost,ss.second});
            }
        }
    }
    int cnt = 0;
    for(int i = 2 ; i<=N; i++){
        if(dik[i]<=K) cnt++; 
    }
    return cnt+1;
}