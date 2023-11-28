#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int S[500],n,C[500],len=0;

void binary_search(int k)
{
    int left=0, right=len;
    
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(C[mid]==k)
        return;
        if(C[mid]<k)
        {
            if(C[mid+1]==-1)
            {
                len++;
                C[mid+1]=k;
            }
            else
                left=mid+1;
        }
        
        else
        {
            if(mid==0||k>C[mid-1])
                C[mid]=k;
            else 
                right=mid-1;
        }
    }
    
    
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
        memset(C,-1,sizeof(C));
        len=0;
        C[0]=S[0];
        for(int i=1; i<n; i++)
            binary_search(S[i]);
        ret.push_back(len+1);
    }
    for(int k : ret)
    {
        cout<<k<<endl;
    }
 
    return 0;
}
