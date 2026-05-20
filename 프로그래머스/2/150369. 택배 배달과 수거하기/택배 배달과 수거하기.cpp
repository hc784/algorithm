#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int lastIdxg = n-1; 
    while(true){
        
    
        bool breFlag = false;
// 1. 해결되지 않은 맨 뒤의 집 탐색
for(int i = lastIdxg ; i >= 0 ; i--){
    
    if(deliveries[i] != 0 || pickups[i] != 0){
        lastIdxg = i;
        breFlag= true;
        break;
    }
}
    if(!breFlag)
        break;
    answer += lastIdxg+1;
    
int del = cap;
int pic = cap;

    while(del>0){
        int lastIdx = -1; 
          // 1. 해결되지 않은 맨 뒤의 집 탐색
        for(int i = lastIdxg ; i >= 0 ; i--){
        if(deliveries[i] != 0){
            lastIdx = i;
            break;
            }
        }   
        if(lastIdx == -1)
            break;
        if(deliveries[lastIdx] >= del){
            deliveries[lastIdx] -= del;
            del = 0;
        }
        else{
            del -= deliveries[lastIdx];
            deliveries[lastIdx] = 0;
        }
    }
    
    
        while(pic>0){
        int lastIdx = -1; 
          // 1. 해결되지 않은 맨 뒤의 집 탐색
        for(int i = lastIdxg ; i >= 0 ; i--){
        if(pickups[i] != 0){
            lastIdx = i;
            break;
            }
        }  
        if(lastIdx == -1)
            break;
        if(pickups[lastIdx] >= pic){
            pickups[lastIdx] -= pic;
            pic = 0;
        }
        else{
            pic -= pickups[lastIdx];
            pickups[lastIdx] = 0;
        }
    }

    
// 3. 해결 안되면? 가져오면서 맨뒤에서 부터 가져오기. 한번더 가기.

// 해결 되면? 
// 가져와야하는 공간만큼은 남겨둬야 한다.
// 그래도 capa가 남으면 그 앞집에서 위 반복.

    }
    return answer*2;
}
