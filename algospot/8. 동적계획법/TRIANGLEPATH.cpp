#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int triangle[100][100],n,cache[100][100];
int recur(int y, int x)
{
    int& ret = cache[y][x];
    
    if(y==n-1)
        return triangle[y][x];
    if(ret!=-1)
    {
        return ret;
    }
    return ret = max(triangle[y][x]+recur(y+1,x),triangle[y][x]+recur(y+1,x+1));
}

int main()
{
    int caseNum;
    cin>>caseNum;  
    while(caseNum--)
    {
        cin>>n;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i+1;j++)
            {
                cin>>triangle[i][j];
            }
        }
            memset(cache,-1,sizeof(cache));
        cout<<recur(0,0)<<endl;
    }

 
    return 0;
}
