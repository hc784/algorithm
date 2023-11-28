#include <iostream>
#include <vector>
using namespace std;

bool ret = false;

void game(vector<vector<int>>& map,vector<vector<int>>& cache,int y, int x,int n)
{
    if(ret==true||y<0||y>=n||x<0||x>=n||cache[y][x]==0)
    {
        return;
    }
    
    if(y==n-1&&x==n-1)
    {
        ret=true;
        return;
    }
    
        
    game(map,cache,y+map[y][x],x,n);
    game(map,cache,y,x+map[y][x],n);
    cache[y][x]=0;
}


int main()
{
    int k;
    cin>>k;
    vector<bool> answer(0);
    while(k--)
    {
        int n;
        cin>>n;
        ret=false;
        vector<vector<int>> map(n,vector<int>(n));
        vector<vector<int>> cache(n,vector<int>(n,-1));
        for(int i=0; i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>map[i][j];
            }
        }
        game(map,cache,0,0,n);
        answer.push_back(ret);

    }
    
    for(int i=0; i<answer.size();i++)
    {
        if(answer[i]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
