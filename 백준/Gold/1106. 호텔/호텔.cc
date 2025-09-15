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

//비용, 고객수
pair<int, int> arr[20];
// cache[고객수] = 최소비용
int cache[1001];
int n, c;
int dp(int num) { // num = 비용? 인원 수? 비용은 return, 인원수를 넘기기?
	if (num >= c) return 0;

	int& ret = cache[num];
	
	if (ret != -1) {
		return ret;
	}

	ret = 1000000;
	for (int i = 0; i < n; i++) {
		ret = min(ret, dp(num + arr[i].second) + arr[i].first);
	}
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> c >> n;

	memset(cache, -1, sizeof(cache));

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	cout<<dp(0);
}


/*
	
*/