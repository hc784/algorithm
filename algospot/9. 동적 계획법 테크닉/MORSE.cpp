#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
int cache[100][100], counta,k;
vector<pair<int,int>> choice;
int morse(int n, int m)
{
    
    if (n + m == 0)
    {
        counta++;
        if (counta == k)
            return -1;
        return 1;
    }
        
    int& ret = cache[n][m];

    if (ret != -1&&counta + ret < k )
    {
        counta += ret;
        
        return ret;
    }
        

    ret = 0;

    if (n != 0)
    {
        int asd = morse(n - 1, m);
        if (asd == -1)
        {
            choice.push_back(pair<int, int>(n, m));
            return -1;
        }
            
        ret += asd;
    }
        
    if (m != 0)
    {
        int asd = morse(n, m-1);
        if (asd == -1)
        {
            choice.push_back(pair<int, int>(n, m));
            return -1;
        }

        ret += asd;
    }

    return ret;
}

int main()
{
    int testcase;
    cin >> testcase;
    vector<string> acm(testcase);
    for(int i=0 ; i<testcase ; i++)
    {
        int n, m;
        cin >> n >> m>>k;
        memset(cache, -1, sizeof(cache));
        counta = 0;
        choice.clear();
        morse(n, m); // n이 먼저옴
        
        for (int j = choice.size() - 1; j > 0; j--)
        {
            if (choice[j].first == choice[j - 1].first)
                acm[i] += "o";
            else
                acm[i] += "-";
        }
        if (choice[0].first == 1)
            acm[i] += "-";
        else
            acm[i] += "o";
    }   
    for (string akd : acm)
    {
        cout << akd << endl;
    }

    return 0;
}
