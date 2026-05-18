#include <bits/stdc++.h>


using namespace std;
 vector<vector<pair<int,int>>> gra;
vector<bool> infec, visited;
int gn, infecNum, maxIn = 0;


void bfs(int sta, int type){
    queue<int> q;
    q.push(sta);
    visited[sta] = true;
    while(!q.empty()){
        int th = q.front();
        q.pop();
        // cout<<gra[th].size()<<endl;
        for(int l = 0 ; l<gra[th].size(); l++ ) // gra[j] size 만큼 반복해서 인접리스트 확인
       {
             
            if(gra[th][l].second == type && !visited[gra[th][l].first]) // 현재 연 type이랑 같으면 감염시키기 나중에 visited 순서 바꾸기
            {
                
                infec[gra[th][l].first] = true;
                q.push(gra[th][l].first);
                visited[gra[th][l].first] = true;
            }
       }
    }

}
// 3파이k 
void ppp(int k, int depth, vector<int> ar){
    
    //1, 2, 3중에 중복 있이 k개를 뽑는 모든 경우의 수
    // 111 112 113 121 122 123 124 ... 
   if(depth == k){
       //  for(auto aa : ar){
       //      cout<< aa<<" ";
       //  }
       // cout<<endl;
       // 이 순서로 열었다 닫는 순서.
       // 구현 방법 : 열었을 때 bfs로 감염되는거 모두 구하기.
       // 감염된 것만 열면 된다. 감염되지 않은건 열필요가 없다. 새로 감염된 것도 먼저 기록하면 안된다.
       // 감염된 것만 주변에 있는거 열어서 다른거로 전파하기. depth를 더 들어갈 필요는 없다.
       infec.assign(gn,false);
       infec[infecNum] = true; 
       for(int i = 0; i<k; i++){
           //ar[i]의 type을 열어서 기존 infection 주변을 탐색하고, 감염 시키기.

           // 1. infection 감염된 거 확인하고, 감염된 거열기
           visited.assign(gn,false);
           for(int j = 0; j<infec.size(); j++){
               if(infec[j]&&!visited[j]){ // 감염된거면
                    bfs(j,ar[i]);
                   // for(auto aa : infec){cout<<aa;}
                   // cout<<j<<endl;
               }
           }

       }
       int thisInfec = 0;
       for(auto as : infec){
           if(as)
               thisInfec++;
       }
       if(maxIn < thisInfec) maxIn = thisInfec;
       return;
    
   }
       
    for(int i = 0 ; i < 3 ; i++){
        ar[depth] = i;
        ppp(k,depth+1, ar);
    }
    
    
}

// 1. 그래프 만들기 2. 타입 별로 열었다 닫았다 완전탐색 3. depth 3이면 감염된거 bfs or dfs로 갯수찾기 4. 최댓값 갱신
int solution(int n, int infection, vector<vector<int>> edges, int k) {
    int answer = 0;
    // 그래프 만들기 그래프는 인접 리스트, 타입을 기록해야함. 
    gra.resize(n); // pair<node, type>
    infec.resize(n);
    gn=n;
    infecNum = infection -1;
    maxIn = 0;
    
    for(auto a : edges){
        gra[a[0]-1].push_back(pair<int,int>(a[1]-1,a[2]-1));
        gra[a[1]-1].push_back(pair<int,int>(a[0]-1,a[2]-1));
    }
    // for(int i = 0 ; i<gra.size(); i++){
    //     cout<< i<< " " ;
    //     for(int j = 0 ; j< gra[i].size() ; j++)
    //     cout<< " " << gra[i][j].first;
    //     cout<<endl;
    // }
    
    // 타입 별로 열었다 닫앗다는? 모든 타입 순서를 구해야함. 111 112 113 114 최대 10번 반복.
    // 순열로 최대 반복 횟수 만큼 모든 경우를 구한다. 3pk 인가? 세개의 숫자를 k개 뽑아서 정렬하기. 
    //  
    ppp(k,0,vector<int>(k));
    answer = maxIn;
    return answer;
}