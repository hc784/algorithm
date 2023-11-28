#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> member(0);
vector<int> fan(0);

vector<int> multiply(const vector<int>& a, const vector<int>& b)
{
	vector<int> c(a.size() + b.size() - 1, 0);

	int aSize = a.size();
	int bSize = b.size();

	for (int i = 0; i < aSize; i++)
		for (int j = 0; j < bSize; j++)
			c[i + j] += a[i] * b[j];

	return c;
}

void addTo( vector<int>& a,  vector<int>& b, int k)
{
	int originalASize = a.size();
	if (a.size() < b.size() + k)
		a.resize(b.size() + k);
	a.push_back(0);

	int aSize = a.size();
	for (int i = originalASize; i < aSize; i++)
		a[i] = 0;

	int bSize = b.size();

	for (int i = 0; i < bSize; i++)
		a[i + k] += b[i];
}

// a -= b
// a>= b인 경우에만 사용 가능하다.
void subFrom(vector<int>& a, const vector<int>& b)
{
	int bSize = b.size();

	for (int i = 0; i < bSize; i++)
		a[i] -= b[i];

}

vector<int> karatsuba(vector<int>& a, vector<int>& b)
{
	int an = a.size(), bn = b.size();

	//a가 b보다 짧을 경우 둘을 바꾼다.
	if (an < bn)
		return karatsuba(b, a);
	//기저 사례 : a나 b가 비어있는 경우
	if (an == 0 || bn == 0)
		return vector<int>();
	//기저 사례 : a가 비교적 짧은 경우, O(n^2) 곱셈으로 변경한다.(성능을 위함)
	if (an <= 50)
		return multiply(a, b);
	int half = an / 2;

	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

	//z2 = a1 * b1
	vector<int> z2 = karatsuba(a1, b1);

	//z0 = a0 * b0
	vector<int> z0 = karatsuba(a0, b0);
	
	//z1 = ((a0 + a1) * (b0 + b1)) - z0 - z2
	addTo(a0, a1, 0);
	addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	//병합 과정
	//ret = z0+z1*10^half + z2 * 10(half*2)
	vector<int> ret(z2.size() + half * 2, 0);
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half * 2);
	return ret;
}

int main()
{
    int n;
    cin>>n;
    vector<int> answer(0);
    while(n--)
    {
        string str;
        cin>>str;
        member.clear();
        fan.clear();
        for(int i=0 ; i<str.size();i++)
        {
            if(str[i]=='F') member.push_back(0);
            else member.push_back(1);
        }

        cin>>str;
        for(int i=0 ; i<str.size();i++)
        {
            if(str[i]=='F') fan.push_back(0);
            else fan.push_back(1);
        }
                reverse(fan.begin(),fan.end());
        if(member.size()>fan.size())
        {
            answer.push_back(0);
            continue;
        }
        vector<int> ret = karatsuba(member,fan);
        
        vector<int>::iterator iter = ret.begin();
        iter+=member.size()-1;
    
        int count=0;
        for(int i=member.size()-1 ; i<fan.size() ; ++i)
        {
            // cout<<*iter;
            if(ret[i]==0) count++;
        }
        answer.push_back(count);
    }
    for(auto& ab : answer)
    cout<<ab<<endl;
    return 0;
}
