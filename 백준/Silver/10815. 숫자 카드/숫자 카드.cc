#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;


int main() {
	vector<int> a;
	
	int n;
	cin >> n;
	while (n--)
	{
		int k;
		scanf("%d",&k);
		a.push_back(k);
	}
	sort(a.begin(), a.end());
	cin >> n;
	while (n--) {
		int k;
		scanf("%d",&k);
		if (binary_search(a.begin(), a.end(), k))
			cout << 1 << " ";
		
		else
			cout << 0 << " ";
	}
		
	
	
	return 0;
}