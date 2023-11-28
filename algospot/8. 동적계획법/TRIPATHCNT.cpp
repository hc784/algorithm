#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int tri[100][100], n, cache[100][100], maxValue, maxValNum;

int tripath(int column, int row) //max 값 계산하는 함수와 경우의 수 계산을 나누기
{
	//tripath의 반환값은 해당 좌표에서 시작해서 나오는 모든 경우의 수에서 나타나는 최댓값을 구하는 것
	int& ret = cache[column][row];
	if (column == n)
		return 0;
	if (ret != -1)
		return ret;

	return ret = tri[column][row] + max(tripath(column + 1, row), tripath(column + 1, row + 1)); // 기존값이 같을 때 밑에 값이 큰게 항상 크다. 메모이제이션이 가능하다.
	//해당층 아래에 있는 두가지 경우중 더 큰 경로를 저장한다.
	
}

int countPath(int column, int row, int preSum)
{
	if (column == n)
		return 1;
	if (maxValue == cache[column][row] + preSum)
	{
		return countPath(column + 1, row, preSum + tri[column][row]) + countPath(column + 1, row + 1, preSum + tri[column][row]);
	}
	else
		return 0;
}

int main()
{
	vector<int> ret;
	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> n;
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				cin >> tri[i][j];

			}
		}
		
		maxValue = tripath(0, 0);
		maxValNum = 0;
		
		ret.push_back((countPath(1, 0, tri[0][0]) + countPath(1, 1, tri[0][0]))/2);
		
	}
	for (int a : ret)
		cout << a<<endl;
	return 0;
}
