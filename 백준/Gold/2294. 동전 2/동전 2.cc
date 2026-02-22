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
#include <unordered_set>

using namespace std;
int n, k, coin[100], cache[10001];
/*
cache[현재값] = 동전 갯수

알고리즘 : 
dp[현재 값] 의 동전 갯수에 들어잇는게 지금 반복보다 작으면 return

각 재귀에서 받는 건 현재 값.
다음 재귀로 들어갈 때 주는건 현재값 + 현재 코인.

모든 코인을 보내야한다.
어떤 코인인지도 넘겨야하나?

한 재귀에서 하는 일 : 코인 더하고, 다음 재귀로 넘기기.
일단 완전탐색 구현

ret <= coinnum으로 하면 다른 코인일 때 다른 코인 더해져야하는데 그게 안더해지고 그냥 return 됨.
그럼 더한 상태로 val을 보내면 되지 않나?
*/
void dp(int val, int coinNum) {
	if (val>k)
		return;
	int& ret = cache[val];
	
	if (ret <= coinNum)
		return;

	ret = coinNum;

	for(int i = 0 ; i<n; i++)
	dp(val+ coin[i], coinNum+1);

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
		


	cin >> n >> k;

	for (int i = 0; i <= k; i++) {
		cache[i] = 987654321;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
	}

	for (int i = 0; i < n; i++)
		dp(coin[i], 1);
	
	if (cache[k] == 987654321)
		cout << -1; 
	else
	cout << cache[k];


}


