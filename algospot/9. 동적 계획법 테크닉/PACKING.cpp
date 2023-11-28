#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
string name[100];
int n,w,wish[100], weigh[100], cache[100][1001], maxweigh;
vector<int> choice;


int packing(int now, int weig)
{
    int bestnext;
    int& ret = cache[now][weig];
    if (now == n)
    {
        return 0;  
    }
    
    if (ret != -1)
        return ret;

    int wishsum = 0;
    if(weig - weigh[now] >= 0 )
        wishsum = wish[now] + packing(now + 1, weig - weigh[now]);

    return ret = max(packing(now + 1, weig), wishsum);
            

}

void recon(int now, int weig)
{
    if (now == n)
        return;

    if (packing(now, weig) == packing(now + 1, weig))
    {
        recon(now + 1, weig);
    }

    else
    {
        choice.push_back(now);
        recon(now + 1, weig - weigh[now]);
    }

}
int main()
{
    int testcase;
    cin >> testcase;
    vector<vector<string>> retChoice(testcase);
    vector<int> retWish;
    for(int i= 0 ; i<testcase ; i++)
    {
        cin >> n >> w;
        memset(cache, -1, sizeof(cache));

        for (int i = 0; i < n; i++)
        {
            cin >> name[i] >> weigh[i] >> wish[i];
        }
        
       
        retWish.push_back(packing(0, w));

        choice.resize(0);
        recon(0, w);
        for(int a : choice)
            retChoice[i].push_back(name[a]);

    }
    for (int i = 0; i < testcase; i++)
    {
        cout << retWish[i] << " " << retChoice[i].size() << endl;
        for (string ss : retChoice[i])
            cout << ss << endl;
    }

    return 0;
}
