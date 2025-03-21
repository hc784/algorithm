#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

/*



*/

int num[100000];

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	sort(num, num + n);

	int minVal = 2011111111;
	int ret[2];

	for (int i = 0; i < n; i++) {
		int start = 0, end = n - 1;
		while (start <= end ) { // 이거 맞는지 확인. >=인가?
			int mid = (start + end) / 2;
			/*
			 num[i] + num[mid] 이 0에 가장 가까운 값. 
			 num[i] + num[mid] > 0 이라면 num[mid]가 더 작은값이어야 한다. end = num[mid]-1
			 num[i] + num[mid]<0 이면 num[mid]가 더 큰 값. start = num[mid]+1
			 num[i] + num[mid]==0 이면 해당값이 result.
			 for 반복마다 num[i] + num[mid] 최솟값 비교하기. 마지막에 최솟값이 나오면.
			*/

			if (num[i] + num[mid] == 0)
			{
				// num i ,mid 대소 비교후 출력. or 결과값 저장
				if (num[i] > num[mid]) {
					ret[0] = num[mid];
					ret[1] = num[i];
				}
				else {
					ret[0] = num[i];
					ret[1] = num[mid];
				}

				goto EXIT;
			}
			
			else if (num[i] + num[mid] > 0)
			{
				end = mid - 1; // 현재 num[i] + num[mid] 값을 저장해서 비교해야 하는지? 0에 가장 가까운 값인지 저장해야하나?
				// 지금까지의 num[i] + num[mid]가 가장 0에 가까운 값을 저장하고, 해당값과 비교해서 더 가깝다면 결과값을 변경하고, 최솟값을 해당 값으로 변경. 
				// 아니라면 그냥 다음 반복.
				// 최솟값 확인 방법 : num[i] + num[mid] 에 절댓값 씌워서 min 값을 저장하기.
				// 최솟값 확인 위치. == 0 인지 확인하고 아니면 최솟값 확인하기. if 문 끝나고 해도 될듯.
			}

			else  {
				start = mid + 1;
			}
			int cal = abs(num[i] + num[mid]);
			if (cal < minVal && i!=mid) {
				minVal = cal;
				if (num[i] > num[mid]) {
					ret[0] = num[mid]; 
					ret[1] = num[i];
				}
				else {
					ret[0] = num[i];
					ret[1] = num[mid];
				}
				
			}
		}

	}

EXIT:
	cout << ret[0] << " " << ret[1];
	return 0;

}