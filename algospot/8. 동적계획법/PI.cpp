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
