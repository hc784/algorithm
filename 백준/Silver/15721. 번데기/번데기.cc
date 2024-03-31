#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;


int main()
{
    int sum = -1;
    int herebool;
    int a,t,b;
    cin >> a >> t >> b;
    int thisIndex = 0;
    int k = 0;
    while (1)
    {
        for (int i = 0; i < 4; i++) {
            if (b == i%2)
                thisIndex++;
            sum=(sum+1)%a;
            if (thisIndex == t) {
                cout << sum;
                goto end;
            }
        }

        
        if (b == 1)
            sum = (sum + 2 + k) % a;
        
        for (int i = 0; i < 2 + k;i++) {   
            thisIndex++;
            sum = (sum + 1) % a;
            if (thisIndex == t) {
                cout << sum;
                goto end;
            }
                
        }

        if (b == 0)
            sum = (sum + 2 + k) % a;
     
        k++;
    }
     
        end:

    return 0;
}