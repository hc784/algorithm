#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int N, K;
struct RNG {
    unsigned seed;
    RNG()
        :seed(1983) {}
    unsigned next() {
        unsigned ret = seed;
        seed = seed * 214013 + 2531011;
        return ret % 10000 + 1;
    }
};


int ites(queue<int> que){
    int retNum = 0;
    RNG seq;
    int sum = 0;
    int countNext = 0;
    while (countNext < N)
    {
        while (sum < K && countNext<N)
        {
            que.push(seq.next());
            countNext++;
            sum += que.back();

        }

       // front 가장 먼저 넣은값 back 마지막
        
        if (sum == K)
        {
            retNum++;

        }
       
        sum -= que.front();
        que.pop();



    }
    
        
    return retNum;

    
}

int main()
{
    int testcase;
    cin >> testcase;
    
    while (testcase--)
    {
        queue<int> que;
        cin >> K >> N;
        cout<<ites(que)<<endl;
        
    }
    
    return 0;
}
