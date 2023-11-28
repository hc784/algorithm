#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cmath>
using namespace std;
int S[100],len, div1, maxdivnum, cache[10][100],INF=987654321;

int calcul(int begin, int end)
{
    int sum=0;
    int aver=int(round((double)accumulate(S+begin,S+end+1,0)/(end-begin+1))); 
    for(int i=begin;i<=end;i++)
    {
        sum+=(S[i]-aver)*(S[i]-aver);
    }
    return sum;
}

void Quantize(int divNum, int inum,int preINum)
{
    if(cache[divNum][preINum+1]!=INF)
        return;
    if(divNum<div1-2)
    {
        Quantize(divNum+1,inum+1,inum);
    }
    
    if(inum>=len-(maxdivnum-divNum)-1) 
        return;
    
        
    Quantize(divNum,inum+1,preINum);
    
    
    if(divNum==maxdivnum) 
    {
        cache[divNum][preINum+1]=min(calcul(preINum+1,inum)+calcul(inum+1,len-1),cache[divNum][preINum+1]);
    }
    
 
    else if(divNum==0)
    {
        cache[0][0]=min(calcul(0,inum)+cache[1][inum+1],cache[0][0]);
    }
    else 
    {
        cache[divNum][preINum+1]=min(calcul(preINum+1,inum)+cache[divNum+1][inum+1],cache[divNum][preINum+1]);
    }
}


int main()
{
    int testCase;
    cin>>testCase;
    

    while(testCase--)
    {
        cin>>len>>div1;
        maxdivnum=div1-2;
        for(int i=0;i<len;i++)
        {
            cin>>S[i];
        }
        for(int i=0; i<10;i++)
        {
            for(int j=0; j<100;j++)
                cache[i][j]=INF;
        }
        sort(S,S+len);
        if(div1==1)
        cout<<calcul(0,len-1)<<endl;
        else if(len<=div1)
        cout<<0<<endl;
        else
        {
            Quantize(0,0,-1);
            cout<<cache[0][0]<<endl; 
        }

    }

    return 0;
}
