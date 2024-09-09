	#define _CRT_SECURE_NO_WARNINGS
	#include <cstdio>
	#include <iostream>
	#include <cstdlib>
	#include <vector>
	#include <algorithm>
	#include <cstring>
	using namespace std;
	vector<int> seq;
	pair<int,int> task[1002];
	int cache[1005][1005];
	int w, n;

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = {0, 1, 0, -1};

	int getD(pair<int,int> a, pair<int,int> b) {
		return abs(a.first - b.first) + abs(a.second - b.second);

	}

	int dp(int a, int b,int fw) {
	
		if (fw == w) {
			return 0;
		}
		int& ret = cache[a][b];
		if (ret != -1)
			return ret;
		ret = 987654321;

		return ret = min(dp(fw, b, fw + 1) + getD(task[a],task[fw]), dp(a, fw, fw + 1)+ getD(task[b], task[fw]));



	}

	void makeSeq(int a, int b,int fw){
		if (fw == w)
			return;

		if (dp(fw, b, fw + 1) + getD(task[a], task[fw]) < dp(a, fw, fw + 1) + getD(task[b], task[fw]))
		/*if (dp(fw,b,fw+1) < dp(a,fw,fw+1))*/
		{
			seq.push_back(1);
			makeSeq(fw, b, fw + 1);
		}
		else {
			seq.push_back(2);
			makeSeq(a, fw, fw + 1);
		}
	}

	int main() {

		cin >> n >> w;

		memset(cache, -1, sizeof(cache));


		for (int i = 0; i < w; i++) {
			scanf("%d %d", &task[i].first, &task[i].second);
		}
		task[1000] = pair<int, int>(1, 1);
		task[1001] = pair<int, int>(n, n);
		cout << dp(1000, 1001,0)<<endl;
	
		makeSeq(1000, 1001,0);


	for (int a : seq) {
		printf("%d\n", a);
	}

	//cout << dp(1000, 1001, 0)<<endl<< dp(1000, 0, 1) << endl<< dp(0, 1001, 1) << endl ;
	return 0;

}