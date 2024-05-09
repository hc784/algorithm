#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main()
{
    string str, fi;
    getline(cin, str, '\n');
    getline(cin, fi, '\n');
    int finum = 0;
    int fiinx = 0;
    for (int i = 0; i < str.size(); i++) {
        bool ok = true;
        for (int j = 0; j < fi.size(); j++)
        {
            if (str[i + j] != fi[j])
            {
                ok = false;
                break;
            }

        }
        if (ok)
        {
            i += fi.size() - 1;
            finum++;
        }

    }

    cout << finum;
    return 0;
}