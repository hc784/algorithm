#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
pair<int, int> map[100000];
//vector<pair<int, int>> map;
bool compare(pair<int, int> i, pair<int, int> j) { return i.second < j.second; }

int main() { // 끝 또는 시작이 같을 경우 더 짧은 것만 남긴다.
	int n;
	cin >> n; 

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &map[i].second, &map[i].first);
	}
	sort(map,&map[n]);
	
	int endTime = map[0].first;;
	int cnt = 1;
	
	for (int i = 1; i < n; i++) {
		if (map[i].second >= endTime)
		{
			cnt++;
			endTime = map[i].first;

		}
	}

	cout << cnt;
	//for (int i = 0; i < n; i++) {
	//	cout << map[i].first << " , " << map[i].second<<endl;
	//}

}