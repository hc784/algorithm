#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

string strList[16];
int n,cache[16][1<<15],cacheDupl[16][16];

int restore(int front, int taken)
{
    int& ret = cache[front][taken];
    if (taken == (1 << n) - 1)
        return strList[front].size();

    if (ret != -1)
        return ret;
    ret = 987654321;
    for (int i = 0; i < n; i++)
    {
        if ((taken & (1 << i)) > 0)
        {
            continue;
        }
        
        int nextTaken = taken | 1 << i;
      
        //i와 front 사이의 중복값 찾는 알고리즘
        if (cacheDupl[front][i] != -1)
        {
            ret = min(ret, (int)(strList[front].size() - cacheDupl[front][i] + restore(i, nextTaken)));
            continue;
        }
            
        int dupl=0;
        for (int j = 0; j < (int)min(strList[front].size(), strList[i].size()) ; j++)
        {
            for (int p = 0; p < j + 1; p++)
            {
                if (strList[front][strList[front].size() - 1 - j + p] != strList[i][p])
                    break;
                
                if (p == j)
                    cacheDupl[front][i]=dupl = j + 1;
            }
        }

        ret = min(ret,(int)(strList[front].size() - dupl + restore(i,nextTaken)));// front랑 다음 front 사이의 중복값을 여기서 빼주는게 맞구나. 그럼 마지막엔 그냥 자기 길이 반환하면 되네

    }
    return ret;
}

void recon(int front, int taken, string& retstr)
{
    if (taken == (1 << n) - 1)
        return;
    int minval = 987654321;
    int minindex=0;
    for (int i = 0; i < n; i++)
    {
        if (taken & (1 << i)) continue;
        int nextTaken = taken | 1 << i;
        int retdef = restore(i, nextTaken);
        if (retdef < minval)
        {
            minval = retdef;
            minindex = i;
        }
    }
    if (cacheDupl[front][minindex] != -1)
    {
        for (int i = 0; i < (int)strList[minindex].size() - cacheDupl[front][minindex]; i++)
        {
            retstr += strList[minindex][cacheDupl[front][minindex] + i];
        }

        recon(minindex, taken | 1 << minindex, retstr);
        return;
    }
    int dupl = 0;
    for (int j = 0; j < (int)min(strList[front].size(), strList[minindex].size()); j++)
    {
        for (int p = 0; p < j + 1; p++)
        {
            if (strList[front][strList[front].size() - 1 - j + p] != strList[minindex][p])
                break;

            if (p == j)
                dupl = j + 1;
        }
    }
        
  
    for (int i = 0; i < (int)strList[minindex].size() - dupl ; i++)
    {
        retstr += strList[minindex][dupl + i];
    }
    


   
 
    recon(minindex, taken | 1 << minindex, retstr);
}



int main()
{
    int testcase;
    cin >> testcase;
    vector<string> ret;
    while (testcase--)
    {
        cin >> n;
        memset(cache, -1, sizeof(cache));
        memset(cacheDupl, -1, sizeof(cacheDupl));
        for (int i = 0; i < n; i++)
        {
            cin>>strList[i];
        }
        int idown = 0;
        for (int i = 0; i < n; i++)
        {
            
            if (idown)
            {
                i--;
                idown = 0;
            }
                
            for (int j = i + 1; j < n; j++)
            {
                if (strList[i].size() > strList[j].size())
                {
                    if (!(string::npos == strList[i].find(strList[j])))
                    {
                        n--;
                        for (int p = j; p < n ; p++) // 배열 한칸씩 당기기
                        {
                            strList[p] = strList[p + 1];
                        }
                        j--;
                    }
                }
                else
                {
                    if (!(string::npos == strList[j].find(strList[i])))
                    {
                        n--;
                        for (int p = i; p < n; p++) // 배열 한칸씩 당기기
                        {
                            strList[p] = strList[p + 1];
                        }
                        idown = 1;;
                        j--;
                    }
                }

            }
        }
        int minval = 987654321;
        int minindex;
        for (int i = 0; i < n; i++)
        {
            int mainTaken = 1 << i;
            int retdef = restore(i, mainTaken);

            if (retdef < minval)
            {
                minval = retdef;
                minindex = i;
            }

        }
        //cout << "답" << minval << endl;
        string rets = strList[minindex];
        recon(minindex, 1 << minindex, rets);
        ret.push_back(rets);
        // 여기서 맨앞 폴문 돌리고, 반환값에다 맨앞 거 더해주기.

    }
    for (string s : ret)
        cout << s << endl;
    return 0;
}
