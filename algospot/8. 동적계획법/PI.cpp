#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#define INF 987654321
using namespace std;

string pi;
int cache[10004];

int a(int begin, int num)
{
    //cout<<"pi : "<<pi.substr(begin,num+1)<< "    cache[10] : "<< cache[10] <<"    cache[13] : " <<  cache[13] << endl;
    int& ret=cache[begin+num+1];

    if(pi.size()==begin)
    {
        return 0;
    } 
    int temp = pi.size()-begin-num-1;
    if(temp==2||temp==1||temp<0)
    {
        return INF;
    }
    
    if(begin>2&&cache[begin]!=INF)
        return cache[begin];
    

    //동일
    string M = pi.substr(begin,num+1);
    
    if(M==string(M.size(),M[0])) return 1+ (ret = min(ret,min({a(begin+num+1,2),a(begin+num+1,3),a(begin+num+1,4)})));
  /*
  문제점 ret에 한턴 빠르게 들어가버림 
  고치려면? 원래는 666 6666 66662 각 값을 비교하고 cache 3에 넣어야하는데 지금은 666에서 뒤에 
  세개가 끝난 뒤에 바로 바로 666을 더하고 바로 ret에 들어감
해결책 
1. cache에 저장할 begin값을 뒤로 땡기고 ,,그리고 아 너 무 복 잡해 
2. begin 값을 앞으로 땡긴다. 땡기려면 앞 재귀의 num값이 필요하다. 이때 num 값을 어떻게 구하냐? <- 폐기
그냥 그자리에 캐쉬 값 저장하는게 
  */
    // 단조증감
    bool progressive = true;
    for(int i=0;i<M.size()-1;i++)
    {
        if(M[i+1]-M[i]!=M[1]-M[0])
        {
            progressive = false;
            break;
        }
    }
        if(progressive&&abs(M[1]-M[0])==1)
            return 2+(ret=min(ret,min({a(begin+num+1,2),a(begin+num+1,3),a(begin+num+1,4)})));

    // 번갈아 나올때
    switch(num)
    {
        case 2:
            if(pi[begin]==pi[begin+2])
            {
                return 4+(ret=min(ret,min({a(begin+3,2),a(begin+3,3),a(begin+3,4)})));
            }
            break;
            
        case 3:
            if(pi[begin]==pi[begin+2]&&pi[begin+1]==pi[begin+3])
            {
  
                return 4+(ret=min(ret,min({a(begin+4,2),a(begin+4,3),a(begin+4,4)})));
            }
            break;
        
        case 4:
            if(pi[begin]==pi[begin+2]&&pi[begin]==pi[begin+4]&&pi[begin+1]==pi[begin+3])
            {

                return 4+(ret=min(ret,min({a(begin+5,2),a(begin+5,3),a(begin+5,4)})));
            }
    }
    
    //등차수열 

    if(progressive) return 5+ (ret=min(ret,min({a(begin+num+1,2),a(begin+num+1,3),a(begin+num+1,4)})));

    return 10+( ret=min(ret,min({a(begin+num+1,2),a(begin+num+1,3),a(begin+num+1,4)})));
    
}
/*
모든 숫자가 같을 때 (예: 333, 5555) 난이도: 1
숫자가 1씩 단조 증가하거나 단조 감소할 때 (예: 23456, 3210) 난이도: 2
두 개의 숫자가 번갈아 가며 출현할 때 (예: 323, 54545) 난이도: 4
숫자가 등차 수열을 이룰 때 (예: 147, 8642) 난이도: 5
그 외의 경우 난이도: 10

12345666661234111123135 
13

1
786432113265412345678
*/


int main()
{
    int c;
    cin>>c;
    while(c--)
    {
        cin>>pi;
        // memset(cache,-1,sizeof(cache));
        for(int& a : cache)
        {
            a=INF;
        }
        cout<<min({a(0,2),a(0,3),a(0,4)})<<endl;
    }

    return 0;
}
/*
5 
12341234 
11111222 
12122222 
22222222 
12673939 
*/