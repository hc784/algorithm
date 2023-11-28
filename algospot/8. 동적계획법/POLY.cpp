#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int length, cache[100][100];
const int MOD = 10000000;

int ab(int n, int first)
{
    if (n == first)
        return 1;
    int& ret = cache[n][first];

    if (ret != 0)
        return ret;

    for (int i = 1; i <= n - first; i++)
    {
        int add = i + first - 1;
        ret = (ret + (add * ab(n - first, i)))% MOD;
        
    }
    return ret % MOD;
}


int main()
{
    int testcase;
    cin >> testcase;
    vector<int> as;
    while (testcase--)
    {
        cin >> length;
        memset(cache, 0, sizeof(cache));
        int result = 0;
        for(int i=1 ; i<=length ; i++)
        result = (result + ab(length, i)) % MOD;
        as.push_back(result);
    }
    for (int a : as)
        cout << a << endl;

    return 0;
}
