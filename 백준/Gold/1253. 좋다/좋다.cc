#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <tuple>

using namespace std;
/*

1. 입력받기.
2. 다른 수의 합 구하기.
합 구해서 좋은지 아닌지 판단하기.

합 구하는 알고리즘.

1. 정렬.
2. 자기보다 크면 줄이고 작으면 높이기.
3. 자기 인덱스는 넘기기.

10
1 2 3 4 5 6 7 8 9 10

예제 출력 
8

*/


int main() {
	
	int n, arr[2000]; 
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	sort(arr, arr + n);
	int good = 0;

	for (int th = 0; th < n; th++) {
		int start = 0, end = n - 1;

		while (start<end)
		{
			//printf(" start: %d end: %d th: %d \n", start, end, th);
			if (start == th ) {
				start++;
				continue;
			}
			else if (end == th)
			{
				end--;
				continue;
			}
				
			if (arr[start] + arr[end] >  arr[th]) {
				end--;
			}
			else if (arr[start] + arr[end] < arr[th]) {
				start++;
			}
			else if (arr[start] + arr[end] == arr[th]) {
				good++;
				break;
			}


		}
		
	}
	cout << good;
	return 0;
}
