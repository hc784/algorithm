#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits){
    int cnt = -1,inten = INF;
    unordered_set<int> gate, summit;  
    for(auto aa : gates) gate.insert(aa);
    
    for(auto aa : summits) summit.insert(aa);
    
    
vector<vector<pair<int,int>> > gra(n+1);
    for(auto a : paths){ // gates는 나가는 것만. summits는 들어오는 것만.
        if(gate.contains(a[0]) || summit.contains(a[1])) // 0이 잇으면 0 -> 1만. summits은 1이 있으면 0->1만
        {
            gra[a[0]].push_back({a[2],a[1]});
        }
        
        else if(gate.contains(a[1]) || summit.contains(a[0])) {
            gra[a[1]].push_back({a[2],a[0]});
        }
        else{
            gra[a[1]].push_back({a[2],a[0]});
            gra[a[0]].push_back({a[2],a[1]});   
        }

        
    }
    
    
        vector<int> dik(n+1,INF);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    for(int kk = 0 ; kk < gates.size() ; kk++ ) {
                q.push({0,gates[kk]});
        dik[gates[kk]]=0;
    }

        while(!q.empty()){
            int time = q.top().first;
            int node = q.top().second;
            q.pop();
            if(time>dik[node]) continue;

            for(auto ss : gra[node]){
                int cost = max(ss.first,time);
                if(cost < dik[ss.second]){ // push하는 기준은? dik[ss.second]가 first와 time 중 큰 값보다 작다면 push할 필요가 없다. 돌아오는 경우는 똑같다.
                    dik[ss.second]=cost; // dik에는 ss.first와 time 중 더 큰 값을 넣어야한다.
                    q.push({cost,ss.second});
                }
            }
        }

        for(int i = 0 ; i<summits.size(); i++){
            if(dik[summits[i]] < inten) {
                inten = dik[summits[i]] ;
                cnt=summits[i];
            }
            else if(dik[summits[i]] == inten && summits[i] < cnt){
                inten = dik[summits[i]] ;
                cnt=summits[i];
            }
        }
    
    
    return {cnt,inten};
}
