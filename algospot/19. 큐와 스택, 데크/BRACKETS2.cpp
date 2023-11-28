#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;



void bracket()
{

}

int main()
{
    int testcase;
    cin >> testcase;
    char asd[130];
    asd['('] = ')';
    asd['['] = ']';
    asd['{'] = '}';
    while (testcase--)
    {
        string str;
        cin >> str;
        stack<char> sta;
        bool check = 1;
        if (str[0] == '}' || str[0] == ')' || str[0] == ']')
            check=0;
        if (0 == str.size() - 1)
        {
            check = 0;
        }
        sta.push(str[0]);

        
        if(check)
        for(int i=1; i<str.size();i++)
        {
            if (str[i] == '}' || str[i] == ')' || str[i] == ']')
            {
                if (sta.empty())
                {
                    check = 0;
                    break;
                }
                if (asd[sta.top()] == str[i])
                {
                    sta.pop();
                }
                else
                {
                    check = 0;
                    break;
                }
            }
            else
            {
                sta.push(str[i]);
                if (i == str.size() - 1)
                {
                    check = 0;
                }
            }
        }
        if (!sta.empty())
            check = 0;

        string as = check ? "YES" : "NO";
       
        cout << as<<endl;
    }

    return 0;
}
