#include <cstdio>
#include <iostream>
#include <queue>
#include <list>



using namespace std;

int main() {
	
	priority_queue<int,vector<int> ,greater<int>> que;
	int n;
	cin >> n; 
	while (n--)
	{
		int a;
		scanf("%d", &a);
		if(a!=0)
		que.push(a);
		if (a == 0)
		{
			if (que.empty())
					printf("%d\n",a);
			else {
				printf("%d\n",que.top());
				que.pop();
			}
		}
	}
	
		
	return 0;
}