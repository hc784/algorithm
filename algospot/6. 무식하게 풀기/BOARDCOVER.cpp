#include <iostream>
#include <vector>
using namespace std;

int X, Y, white, result;

void a(int x,int y,vector<vector<string>>& map,int count)
{
    

    if(x>=X+1)
    {
        a(1,y+1,map,count);
        return;
    }

    if(y>=Y)
    {
        if(count==white/3)
        {
            result++;
            return;
        }

        else 
            return;
    }
    if(map[y][x]=="#")
    {
        a(x+1,y,map,count);
        return;
    }
        
    
    
    if(map[y][x-1].compare(".")==0&&map[y+1][x-1].compare(".")==0)
    {
        map[y][x]="#";
        map[y][x-1]="#";
        map[y+1][x-1]="#";
        count++;
        a(x+1,y,map,count);
        map[y][x]=".";
        map[y][x-1]=".";
        map[y+1][x-1]=".";
        count--;
    }
    if(map[y][x-1].compare(".")==0)
        return;
        
    if(map[y+1][x].compare(".")==0&&map[y+1][x-1].compare(".")==0)
    {
        map[y][x]="#";
        map[y+1][x]="#";
        map[y+1][x-1]="#";
        count++;
        a(x+1,y,map,count);
        map[y][x]=".";
        map[y+1][x]=".";
        map[y+1][x-1]=".";
        count--;
    }
    
    if(map[y][x+1].compare(".")==0&&map[y+1][x+1].compare(".")==0)
    {
        map[y][x+1]="#";
        map[y+1][x+1]="#";
        map[y][x]="#";
        count++;
        a(x+1,y,map,count);
        map[y][x+1]=".";
        map[y+1][x+1]=".";
        map[y][x]=".";
        count--;
    }
    
    if(map[y+1][x].compare(".")==0&&map[y+1][x+1].compare(".")==0)
    {
        map[y][x]="#";
        map[y+1][x]="#";
        map[y+1][x+1]="#";
        count++;
        a(x+1,y,map,count);
        map[y][x]=".";
        map[y+1][x]=".";
        map[y+1][x+1]=".";
        count--;
    }
    
        

    
    if(map[y][x+1].compare(".")==0&&map[y+1][x].compare(".")==0)
    {
        a(x+1,y,map,count);
    }
    
    
    
    
            
}

int main()
{
    int num;
    vector<int> end_result;
    cin>>num;
    for(int z=0;z<num;z++)
    {
        white=0;
        result=0;
        cin>>Y>>X;
        vector<vector<string>> map;
        string k;
        
        for(int i=0;i<Y+1;i++)
        {
            
            map.push_back(vector<string>());
            if(i==Y)
            {
                for(int j=0;j<X+2;j++)
                {
                    map[i].push_back("0");
                }
                break;
            }
            cin>>k;
            for(int j=0;j<X+2;j++)
            {
                if(j==X+1||j==0)
                {
                    map[i].push_back("0");
                    continue;
                }
                map[i].push_back(k.substr(j-1,1));
                if(map[i][j].compare(".")==0)
                 white++;
            }
        }
        if(white%3!=0)
        {
            end_result.push_back(0);
            continue;
        }
            
        
        
        a(1,0,map,0);
        end_result.push_back(result);

    }
    for(auto& m : end_result)
    cout<<m<<endl;
    
    return 0;
}
