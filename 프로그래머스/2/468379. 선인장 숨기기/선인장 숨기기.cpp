#include <bits/stdc++.h>

using namespace std;

/*
1. 맵에 떨어지는 순서 기록
2. 모노톤 덱 만들기.
3. 슬라이딩 윈도우
*/
vector<vector<int>> map1;

// 가장 작은값 값이 맨 앞. 푸쉬하는 값보다 큰 값을 모두 pop back.
void dpush(int v, deque<int>& mono){
    if(v == 555555)
        return;
    while(!mono.empty() && mono.back()>v){
        mono.pop_back();
    }
    mono.push_back(v);
}
// 윈도우 범위를 벗어나는 값은 항상 가장 오래된 값. 그 값이 가장 큰 값이라면 맨 앞에 위치한다. 
// 맨 앞에 있는 값이 벗어난 값이랑 같으면 pop. 다르면 이미 pop된 상태.
void dpop(int v, deque<int>& mono){
    if(v != 555555&& !mono.empty() && mono.front()==v){
        mono.pop_front();
    }
}

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    vector<int> answer;
    map1.assign(m,vector<int>(n,555555));
    deque<int> mono;
    
    vector<vector<int>> row(m, vector<int>(n-w+1,555555));
  // 떨어지는 순서 기록
    for(int i = 0 ; i<drops.size() ; i++)
    {
        map1[drops[i][0]][drops[i][1]] = i;
    }
    // 슬라이딩 윈도우
    // 1. 선인장 가로 범위 w 만큼 모노톤 덱에 넣기. 
    
    for(int i = 0 ; i<m ; i++){
        mono.clear();
        for(int j= 0 ; j<w ; j++){
            
            dpush(map1[i][j],mono);
        }
        if(!mono.empty())
            row[i][0] = mono.front();

        // cout<<"test" << mono.front()<< endl; 
        // 2. 한칸씩 옮기면서 범위 벗어나는거 팝, 들어오는거 푸쉬. 끝 인덱스는? i = 0 ;i  < n-w
        for(int j = 1 ; j<n-w+1 ; j++){
            dpop(map1[i][j-1],mono);
            dpush(map1[i][j+w-1],mono);
            // if(!mono.empty())
            // cout<<j+w-1<<"::  "<< mono.front()<< endl; 

                if(!mono.empty() && row[i][j] > mono.front()){
                      row[i][j] = mono.front();
                }
        }
    }
    
//     for(int i = 0 ; i<row.size(); i++){
//         for(int j = 0 ; j<row[i].size(); j++){
//             cout<<row[i][j]<<" ";
//         }
//         cout<<endl;
//     }
    
    
    // 4. m개의 모노톤 덱을 대상으로 n개의 모노톤덱을 만들기.
    vector<vector<int>> col(m-h+1, vector<int>(n-w+1,555555));
    
    for(int i = 0 ; i<n-w+1 ; i++){
        mono.clear();
        for(int j= 0 ; j<h ; j++){
            
            dpush(row[j][i],mono);
        }
        if(!mono.empty())
            col[0][i] = mono.front();

        // cout<<"test" << mono.front()<< endl; 
        // 2. 한칸씩 옮기면서 범위 벗어나는거 팝, 들어오는거 푸쉬. 끝 인덱스는? i = 0 ;i  < n-w
        for(int j = 1 ; j<m-h+1 ; j++){
            dpop(row[j-1][i],mono);
            dpush(row[j+h-1][i],mono);
            // if(!mono.empty())
            // cout<<j+w-1<<"::  "<< mono.front()<< endl; 

                if(!mono.empty() && col[j][i] > mono.front()){
                      col[j][i] = mono.front();
                }
        }
    }
    int x=-1,y=-1,maxv= -1;
    for(int i = 0 ; i<col.size(); i++){
        for(int j = 0 ; j<col[i].size(); j++){
            if(maxv<col[i][j]){
                x=i; 
                y=j;
                maxv=col[i][j];
            }
        }
        cout<<endl;
    }
    
   answer.push_back(x);
    
   answer.push_back(y);
    return answer;
}