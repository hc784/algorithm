#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int S[500],k , cacheLen[501], n,result[500], MOD=2000000000;
long long cacheCount[500][500];

int lis(int start)
{
    int& ret = cacheLen[start + 1];
    if (ret != -1) return ret;

    ret = 1;

    for (int next = start + 1; next < n ; next++)
    {
        if (start == -1 || S[start] < S[next])
            ret = max(ret, lis(next) + 1);
    }
    return ret;
}

long long count(int Lisval,int minval,int index)
{
    long long& ret = cacheCount[Lisval][index];


    if (Lisval == 0)
        return 1;

    if (ret != -1)
        return ret;
    long long countnum = 0;
    for (int i = index; i < n; i++)
    {
        if (lis(i) == Lisval && minval < S[i]) // minval보다는 크면서 그 중에 가장 작은값이면서 cache가 Lisval인값
        {
            long long as = count(Lisval - 1, S[i], i + 1);
            as = MOD < as ? MOD : as;
            countnum = countnum + as;
        }
    }
   
    return ret= countnum;
}

int klis(int lisval, int minval, int minindex)
{
    int whatmin = 100000;
   
    if (lisval == 0)
        return 0;

    for (int i = minindex; i < n; i++)
    {
        if (lis(i) == lisval && minval < S[i] && S[i] < whatmin)
        {
            whatmin = S[i];
            minindex = i;
        }
    }
   
       long long countk = count(lisval - 1, whatmin, minindex + 1);
       if (countk >= k)
       {
           result[lis(-1) - 1 - lisval] = S[minindex];
           klis(lisval - 1, S[minindex], minindex);
       }
           
       else if (countk < k)
       {
           k -= countk;
           klis(lisval, whatmin, 0);

       }
           
       
    
    return 0;
}



int main()
{
    
    int testcase;
    cin >> testcase;
    vector<vector<int>> retS(testcase);
    vector<int> retlis;
    for(int t = 0 ; t < testcase; t++)
    {
        
        cin >> n >> k;
        memset(cacheLen, -1, sizeof(cacheLen));
        memset(cacheCount, -1, sizeof(cacheCount));
        for (int i = 0; i < n; i++)
        {
            cin >> S[i];
        }
        int  lisval = lis(-1)-1 ;
        retlis.push_back(lisval);
        klis(lisval, 0, 0);
        for (int i = 0; i < lisval; i++)
            retS[t].push_back(result[i]);

    }

    for (int i = 0; i < testcase; i++)
    {
        cout << retlis[i] << endl;
        for (int ret : retS[i])
            cout << ret << " ";
        cout << endl;
    }
    return 0;
}
