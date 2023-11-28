#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int S[500],n,cache[501]; 

int MaxSize(int index,int lastIndex)
{
    int& ret = cache[index];
    if(index==n)
        return 1;
 
    if(lastIndex==-1||S[lastIndex]<S[index]) 
    {
        if(ret!=-1)
        {
            return max(MaxSize(index+1,lastIndex),ret); // count 없이 코딩 해보기 2. 이진탐색으로 코딩해보기 
        }
        
        ret = MaxSize(index+1,index)+1;  
        return max(MaxSize(index+1,lastIndex),ret);
    } 
    else
    {
        return MaxSize(index+1,lastIndex);
    }
} 


int recur()
{
    int maxLength=0;
    for(int i=0; n-i>maxLength ; i++) 
    {
        int& ret = cache[i]; 
        if(ret != -1)
            continue;

        if(S[i+1]>S[i])
            maxLength=max(MaxSize(i,i),maxLength);
    }
    return maxLength;
}

int main()
{
    int caseNum;
    cin>>caseNum;  
    vector<int> ret(0);
    while(caseNum--)
    {
        cin>>n;
        
        for(int i=0;i<n;i++)
        {
            cin>>S[i];
        }
        memset(cache,-1,sizeof(cache));
        ret.push_back(MaxSize(0,-1)-1);
    }
    for(int k : ret)
    {
        cout<<k<<endl;
    }
 
    return 0;
}
