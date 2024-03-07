#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	
	int a;
	cin >> a;
	int minVal = 1000000, maxVal = -1000000;
	
	for (int i = 0; i < a;i++) {
		int x;
		cin >> x;
		maxVal = max(maxVal, x);
		minVal=min(minVal, x);
	}

	cout << minVal << " " << maxVal;

	return 0;
}