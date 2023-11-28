#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
int len, day, minday;
double cache[1001][1001];



double combination(int n, int r)
{
	if (r == 0 || n == r)
		return 1.0;
	double& ret = cache[n][r];
	if (ret != 0)
		return ret;

	return ret = combination(n - 1, r - 1) + combination(n - 1, r);
}


double snail()
{
	double ret = 0;
	for (int i = minday; day >= i; i++)
	{
		ret += pow(0.75, i) * pow(0.25, day - i) * combination(day, i);
	}
	return ret;
}

int main()
{
	int testcase;
	cin >> testcase;
	vector<double> ret(0);
	memset(cache, 0, sizeof(cache));
	while (testcase--)
	{
		
		cin >> len >> day;
		if (len <= day) {
			ret.push_back((double)1);
			continue;
		}

		if (len > 2 * day) {
			ret.push_back((double)0);
			continue;
		}

		for (int i = 0; ; i++)
		{
			if (len - day - i == 0)
			{
				minday = i;
				break;
				
			}
		}
		
		ret.push_back(snail());
		

	}
	for(double k : ret)
	printf("%.11f\n", k);

}
