#include <bits/stdc++.h>

using namespace std;
int cache[100001][2], n1;
vector<int> top1;
/*
top이 있는 경우는 아래것만 하고 있으면 위에것도 하기.
마름모가 넘어온 상태에 따라 처리하기.
*/
int dp(int idx, int state){
    int& ret = cache[idx][state];
    if(idx == n1){
        if(state == 1)
        return 0;
        else return 1;
    }
    
    if( ret != -1){
        return ret % 10007;
    }
    ret = 0;
    // top 이 있는 경우
    // 이전 마름모 상태에 따라 여기서 나올 경우의 수를 계산하기.
    // 넘어왔으면? 경우의 수는 2개. 마름모를 넘기거나 삼각형만 있거나.
    // 안넘어왔으면? 삼삼삼 or 마 삼  삼 마,//// 여기는 뒤로 넘어감 , 마마, 삼삼 마
    // 안넘어가는 경우의 수 3, 넘어가는 경우의 수 2
    if(top1[idx]==1){
        if(state == 0) // 안넘어온 경우
        {
            ret += 3*dp(idx+1, 0) % 10007; // 안넘어 가는 경우
            
            ret += 2*dp(idx+1, 1) % 10007; // 넘어 가는 경우
            
        }
        else if(state == 1){
            ret += dp(idx+1, 0) % 10007; // 안넘어 가는 경우
            
            ret += dp(idx+1, 1) % 10007 ; // 넘어 가는 경우
        }
    }
    // top이 없는 경우.
    // 넘어오면 삼 or 마 두가지
    // 안넘어오면 삼 삼, 마, 삼 마
    // 넘어가는경우는 삼 마 한가지, 안넘어가는거 2가지.
    else{
        
        if(state == 0) // 안넘어온 경우
        {
            ret += 2*dp(idx+1, 0) % 10007 ; // 안넘어 가는 경우
            
            ret += dp(idx+1, 1)% 10007 ; // 넘어 가는 경우
            
        }
        else if(state == 1){
            ret += dp(idx+1, 0)% 10007; // 안넘어 가는 경우
        
            ret += dp(idx+1, 1)% 10007; // 넘어 가는 경우
        }
        
    }
    // cout<<idx<< " , "<<ret<<endl;
    // 이거 경우의 수를 넘기면 되나.
    // 현재 경우의 수를 곱해서 이후 경우의 수 반환 된걸 cache에 저장하기.
    // 넘어가는 경우와 안넘어가는 경우는 별개로 저장하기.
    // return은 두 경우를 더해서 return하기.
    ret= ret%10007;
    return ret;
}

int solution(int n, vector<int> tops) {
    top1.swap(tops);
    memset(cache,-1,sizeof(cache));
    int answer = 0;
    n1 = n;
    
    answer+= dp(0,0)% 10007;
    
    answer+= dp(0,1)% 10007;
    return answer % 10007;
}