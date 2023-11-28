#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXX = 1000000001;
int cache[100], Scount[50],n, p, l;
string retstring;

int count(int generation) 
{
    if (generation >= 29)
        return MAXX;
    if (generation == 0)
        return Scount[generation] = 1;
    if (Scount[generation] != -1)
        return Scount[generation];
    return Scount[generation] = min(MAXX, count(generation - 1) + (int)pow(2, generation - 1) * 3);

}


void dragon(const string& seed, int generation) 
{
    if (p < -(l - 1))
        return;
    if (generation == n + 1)
    {
        if (-(l - 1) <= p && p <= 0)
        {
                
            if (seed[0] == 'X')
                retstring += "X";
            if (seed[0] == 'F')
                retstring += "Y";
        }
        p -= 1;
        return;
    }
    int cnt = count(n - generation);
    for (int i = 0; i < seed.size(); i++)
    {
        if (seed[i] == 'X')
        {
            if (cnt < p) {
                p -= cnt;
                continue;
            }
            else if (cnt>=p)
                dragon("X+YF", generation + 1);
        }
            
        if (seed[i] == 'Y')
        {
            if (cnt < p) {
                p -= cnt;
                continue;
            }
            else if (cnt >= p)
                dragon("FX-Y", generation + 1);
        }
        if (seed[i] == '+')
        {
            if (-(l - 1) <= p && p <= 0)
                retstring += "+";
            p -= 1;
        }
        if (seed[i] == '-')
        {
            if (-(l - 1) <= p && p <= 0)
                retstring += "-";
            p -= 1;
        }
        if (seed[i] == 'F')
        {
            if (-(l - 1) <= p && p <= 0)
                retstring += "F";
            p -= 1;
        }

           
    }

}   

int main()
{
    vector<string> ret;
    int testcase;
    cin >> testcase;
    memset(Scount, -1, sizeof(Scount));
    while (testcase--)
    {
    
        cin >> n >> p >> l;
        p = p - 1;
        retstring = "";
        dragon("FX", 0);
        ret.push_back(retstring);
    }
    for (string a : ret)
        cout << a << endl;
    return 0;
}
