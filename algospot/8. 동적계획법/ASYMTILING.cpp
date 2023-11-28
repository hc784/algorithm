#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#define MOD 1000000007
using namespace std;
int len, cache[101];



int tiling(int n)
{
	if (n == len)
		return 1;
	else if (n > len)
		return 0;
	int& ret = cache[n];
	if (ret != -1)
		return ret;
	return ret=(tiling(n + 1) + tiling(n + 2))% 1000000007;
}

int main()
{
	int testcase;
	cin >> testcase;
	vector<int> ret(0);

	while (testcase--)
	{
		memset(cache,-1,sizeof(cache));
		cin >> len;
		
			
		int til = tiling(0);
		int asym;

		memset(cache, -1, sizeof(cache));
		if (len % 2 == 0)
		{
			len = len / 2 ; 
			til = (til- tiling(0) +MOD)%MOD;
			memset(cache, -1, sizeof(cache));
			len = len -1;
			asym = tiling(0);
		}
		else
		{
			len = len / 2;
			asym = tiling(0);
		}
		
		ret.push_back((til-asym+MOD)%MOD);

	}
	for (int k : ret)
		printf("%d\n", k);

}
