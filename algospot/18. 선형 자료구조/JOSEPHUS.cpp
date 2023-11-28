#include <iostream>
#include <list>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	vector<vector<int>> ret(tc);
	int testcase = tc;
	while (tc--)
	{
		int n, k;
		cin >> n >> k;

		list<int> li(n);
		int i = 0;
		for (list<int>::iterator iter = li.begin(); i<n; iter++,i++)
		{
			*iter = i;
		}
		int	lisize = n;
		list<int>::iterator iter = li.begin();
		while (lisize != 2)
		{
			list<int>::iterator nextiter = next(iter,1);
			if (nextiter == li.end())
				nextiter = li.begin();
			li.erase(iter);
			lisize--;
			for (int i = 0; i < k - 1; i++)
			{
				nextiter++;
				if (nextiter == li.end())
					nextiter = li.begin();
				
			}
			iter = nextiter;

		}

		ret[testcase - tc-1].push_back(*li.begin()+1);
		ret[testcase - tc-1].push_back(*(++li.begin())+1);
			
	}
	for (vector<int> as : ret)
	{
		for (int ad : as)
			cout << ad << " ";
		cout << endl;
	}


	return 0;
}
