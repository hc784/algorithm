#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, ar[9];
bool arr[9];
void a(int depth) {

	if (depth == m)
	{
		for (int i = 0; i < m; i++) {
			printf("%d ",ar[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!arr[i]) {
			
			arr[i] = true;
			ar[depth] = i;
			a(depth + 1);
			arr[i] = false;
		}
		
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < 9; i++)
		arr[i] = false;
	a(0);
}