#include <iostream>
#include <cstring>
using namespace std;
int cache[101];

int tiling(int c)
{
	if (c == 0)
		return 1;
	
	if (c < 0)
		return 0;

	if (cache[c] != -1)
		return cache[c];

	return cache[c] = (tiling(c - 1) + tiling(c - 2))%1000000007;
	
}


int main()
{
	int testcase;
	cin >> testcase;
	while (testcase--)
	{
		int c;
		cin >> c;
		memset(cache, -1, sizeof(cache));
		cout << tiling(c) << endl; // % 1000000007;
	}

	return 0;
}
