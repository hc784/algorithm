#include <string>
#include <vector>

using namespace std;
#define MAX 987654321
/*
dp. 
cache[알고력][코딩력] = 최단시간
*/
int maxal=-1,maxco=-1;
vector<vector<int>> cache;
// 분기 어떤 문제로? +1로 선택? 모든 문제를 돌아야한다. 모든 문제 대신 +1을 하는경우? 
int dp(int al, int co, vector<vector<int>>& p){
    if(al>=maxal)
        al = maxal;
    if(co>=maxco)
        co= maxco;
    int& ret = cache[al][co];
    if(al>=maxal && co>=maxco) return 0; 
    if(ret != MAX) return ret;
    
    int minTime=MAX;
    for(auto a : p){
        if(al>=a[0]&&co>=a[1] && (a[2] != 0 || a[3] !=0)){ // al과 co가 문제 요구량보다 크면서, 주는게 둘다 0이 아닌경우. 하나만 0인 경우는 들어간다.
                if(al>=maxal ){ // max al보다 큰경우
                    if(a[3]!=0){
                        if(co<maxco)
                             minTime =  min(dp(al,co+a[3],p)+a[4], minTime);
                    }
                   
                }
                else if(co>=maxco){ // max al보다 al이 작고, co가 maxco보다 큰경우.
                    if(a[2]!=0)
                    minTime =  min(dp(al+a[2],co,p)+a[4], minTime);
                }
                else minTime =  min(dp(al+a[2],co+a[3],p)+a[4], minTime); // al이 maxal보다 작고, co가 maxco보다 작은 경우 이게 돌아간다.
            }
            
    }
    if(al<maxal)
    minTime =  min(dp(al+1,co,p)+1, minTime);
    if(co<maxco)
    minTime =  min(dp(al,co+1,p)+1, minTime);
    
    return ret = minTime;
}
int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    cache.assign(1000, vector<int>(1000,MAX));
    
    for(auto a : problems){
        if(maxal<a[0]) maxal = a[0];
        if(maxco<a[1]) maxco = a[1];
    }
    answer = dp(alp,cop,problems);
    
    return answer;
}