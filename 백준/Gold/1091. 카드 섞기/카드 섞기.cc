#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
int p[48], s[48], n;
int* a, *t;
vector<set<int>> ret(3), tempV(3); 

bool vecSetEqu();

// s 섞는 순서
// p 가야하는 카드
bool ok1() { // temp에 넣어두고 p는 미리 ret에 넣어두고 두개 비교해서 맞는지 확인
	
	for (int i = 0; i < 3; i++)
	{
		tempV[i].clear();
		tempV[i] = set<int>();
	}
	for (int i = 0; i < n; i++)
	{
		tempV[i%3].insert(a[i]); // i번카드가 p[i]번 벡터에 들어가야함
	}
	return vecSetEqu();
}

bool vecSetEqu()
{	
	for (int i = 0; i < 3; i++)
	{
		if (ret[i]!=tempV[i])
			return false;
	}
	return true;
}
/*
 a[i]번째 있는 카드를 a[s[i]]로 이동
a[s[i]]에 있던 카드는 ?
새로운 문자열은 만들어서 거기에 이동한 문자를 저장하기
*/
void shuffle() { 
	int*  b = new int[n];
	for (int i = 0; i < n; i++)
	{
		b[s[i]] = a[i];
	}
	delete a;
	a = b;
		
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p[i]); // p 가야하는 카드
	}
	for (int i = 0; i < n; i++)
	{	
		scanf("%d", &s[i]);
	}

	int ok = -1;
	a = new int[n];
	t = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
		t[i] = i;
	}
	
	for (int i = 0; i < n; i++)
	{
		ret[p[i]].insert(i); // i번카드가 p[i]번 벡터에 들어가야함
	}
	//for (auto& ca : ret)
	//{
	//	
	//	for (auto& sda : ca)
	//	{
	//		cout << sda << " ";
	//	}
	//		cout << endl;
	//}
			

	if (ok1()) {
		ok = 0;
		goto end1;
	}
	shuffle();
	for(int i = 1 ; !equal(t,t + n, a) ; i++)
	{
		if (ok1())
		{
			ok = i;
			goto end1;
		}
		shuffle();

			
		//for (int i = 0; i < n; i++)
		//	cout << a[i] << " ";
	}

	
	end1:
	cout << ok << endl;
	

	


	return 0;
}