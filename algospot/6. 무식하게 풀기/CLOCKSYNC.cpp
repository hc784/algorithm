#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> link_clock({{0,1,2},{3,7,9,11},{4,10,14,15},{0, 4, 5, 6, 7},{6, 7, 8, 10, 12},{0, 2, 14, 15},{3, 14, 15},{4, 5, 7, 14, 15},{1, 2, 3, 4, 5},{3, 4, 5, 9, 13}});
int ret=9999;
vector<int> comb_arr(20);
vector<int> result(0);
void set_clock(int button,vector<int>& clock_board)
{
    for(int i=0;i<link_clock[button].size();i++)
    {
        clock_board[link_clock[button][i]]+=3;
        if(clock_board[link_clock[button][i]]==15)
            clock_board[link_clock[button][i]]=3;
    }
} 

void return_clock(int button,vector<int>& clock_board)
{
    for(int i=0;i<link_clock[button].size();i++)
    {
        clock_board[link_clock[button][i]]-=3;
        if(clock_board[link_clock[button][i]]==0)
            clock_board[link_clock[button][i]]=12;
    }
} 

bool ok(vector<int>& clock_board)
{
    for(int i=0;i<16;i++)
    {
        if(clock_board[i]!=12)
            return false;
    }
    return true;
}

void comb(int count, int index,vector<int> clock_board,int num_count)
{
    if(count==10)
    {
        if(ok(clock_board))
        {
            if(ret>num_count)
            {
                ret=num_count;
            }
        }
        return;
    }
       
    
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<i;j++)
            set_clock(count,clock_board);
        num_count+=i;
        comb(count+1,i,clock_board,num_count);
        for(int j=0;j<i;j++)
            return_clock(count,clock_board);
        num_count-=i;
        
    }
}



int main()
{
    int num;
    cin>>num;
    for(int j=0;j<num;j++)
    {
        int k;
        vector<int> clock_board(16);
        for(int i=0;i<16;i++)
        {
            cin>>k;
            clock_board[i]=k;
        }
        
        ret=9999;

        comb(0,0,clock_board,0);
        if(ret<=100)
        {
            result.push_back(ret);
            continue;
        }
        result.push_back(-1);
    
    }
    for(auto& ab : result)
        cout<<ab<<endl;
    return 0;
}
