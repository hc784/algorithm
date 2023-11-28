#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;
string e, digits;
int cache[1<<14][20][2],m;



int numset(int index, int mod, int taken, int less)
{
    int& ret = cache[taken][mod][less];
    if (index== digits.size())
    {
        if (mod == 0 && less == 1)
            return 1;
        else return 0;
    }
        
    if (ret != -1)
        return ret;
   
    ret = 0;
    for (int i = 0; i < digits.size(); i++) {

        int nextless= less;
        if (digits[i] > e[index] && less == 0)
        {
            continue;
        }
        else if (digits[i] < e[index])
            nextless = 1;

        if ((taken&(1<<i))==0 && (i == 0 || digits[i] != digits[i - 1] || !(taken&(1<<i-1)) == 0))
        {
            int nexttaken = taken|(1<<i);
            int nextmod = (mod * 10 + digits[i] - '0') % m;
            ret += numset(index+1,nextmod,nexttaken, nextless);
            ret %= MOD;

        }

    }
    
    return ret;
}


int main()
{
    int testcase;
    cin >> testcase;
    vector<int> ret;
    while (testcase--)
    {
       
        cin >> e >> m;
        digits = e;
        sort(digits.begin(), digits.end());
        memset(cache,-1,sizeof(cache));
        ret.push_back(numset(0,0,0,0));

    }
    for (int a : ret)
        cout << a << endl;
    return 0;
}
