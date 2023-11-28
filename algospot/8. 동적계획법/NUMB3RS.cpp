#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int>> map;
vector<int> probability;
int town, day, prison, target;
double cache[101][51];
double numb(int depth, int nowTown)
{
	double& ret = cache[depth][nowTown];

	if (depth == day - 1)
	{
		if (map[nowTown][target] == 1)
			return 1.0 / probability[nowTown];
		
		else
			return 0;
	}

	if (ret > -0.5)
		return ret;

	ret = 0;

	for (int i = 0; i < town; i++)
	{
		if (map[nowTown][i] == 1)
		{
			ret += numb(depth + 1, i) / probability[nowTown];
		}
	}
	return ret;

}

int main()
{
	int testcase;
	cin >> testcase;
	vector<vector<double>> result(testcase);
	for (int k=0; k<testcase ; k++)
	{

		cin >> town >> day >> prison;
		map.resize(town);
		probability.resize(town,0);
		for (int i=0; i<town ; i++)
		{
			probability[i] = 0;
		}
		for (int i = 0; i < town; i++)
		{
			map[i].resize(town);
			for (int j = 0; j < town; j++)
			{
				cin >> map[i][j];	
				if (map[i][j] == 1)
					probability[i]++; // 답 아니면 연결된 곳이 없는 경우 예외처리
			}
		}


		int caseProba;
		cin >> caseProba;
		result[k].resize(caseProba);
		for (int i = 0; i < caseProba; i++)
		{
			cin >> target;
			for (int i = 0; i < 101; i++)
			{
				for (int j = 0; j < 51; j++)
				{
					cache[i][j] = -1;
				}
			}
			result[k][i]=(numb(0, prison));
		}
	}
	for (vector<double> re1 : result)
	{
		for (double re2 : re1)
		{
			printf("%.8f ", re2);
		}
		cout << endl;
	}
	

	return 0;
}
