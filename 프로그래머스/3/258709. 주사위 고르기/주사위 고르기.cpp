#include <bits/stdc++.h>

using namespace std;
int n,r;
vector<vector<int>> dice1;

void sumDiceF(vector<int> combDice, vector<int>& diceSum){
    
        for(int i = 0; i<r ; i++){
            vector<int> nextSum(501,0);
   
            for(int j = 0 ; j<500 ; j++){
                
                if(diceSum[j]==0){
                    continue;
                }   
                for(int k = 0 ; k < 6 ; k++)
                {
                    
                    nextSum[j+dice1[combDice[i]][k]]+= diceSum[j];
                } 
            }
            diceSum = nextSum;
        } 
    
    
}
vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    vector<vector<int>> vicTable;
    vector<vector<int>> combRet;
    n = dice.size();
    r = n/2;
    dice1=dice;
    vector<int> comb;
    for(int i = 0 ; i<r; i++){
        comb.push_back(0);
    }
    for(int i = 0 ; i<n-r; i++){
        comb.push_back(1);
    }
    
    do{
        
        vector<int> combDice, combDice2;
        vector<int> diceSum(501,0),diceSum2(501,0);
        diceSum[0] = 1;
        diceSum2[0] = 1;
        for(int i = 0 ; i < n ; i++){
            if (comb[i] == 0)
                combDice.push_back(i);     
            else if (comb[i] == 1)
                combDice2.push_back(i);     
 
            }
        combRet.push_back(combDice);
        sumDiceF(combDice,diceSum);
        sumDiceF(combDice2,diceSum2);
        
        //  for(int s = 0 ; s<20 ;s++)cout<<diceSum2[s]<<" ";
        // cout<<endl; // 각 조합마다 모든 합의 경우의 수를 구함. 반대편 것도 구해야함.
        // 다음으로 할 일. 합이랑 합을 비교해서 승무패 구하기. 여기선 빈도수로.
        // sum이 같으면 무승부, sum이 크면 승. 작으면 패.
        // 해당 sum보다 위에있는 수 X 빈도수 = 승.
        int dice2Sum = pow(6,r);

        int lowSum = 0, highSum = dice2Sum;
        vector<int> vict(3,0);
        for(int i = 1; i<501 ;i++){

            
            int sameSum = diceSum2[i];

            highSum -= sameSum;
            
            vict[1]+=sameSum*diceSum[i];
            vict[2]+=highSum*diceSum[i];
            vict[0]+=lowSum*diceSum[i];
            

            lowSum += sameSum;
                
            
        }
        vicTable.push_back(vict);
    }
    
    while (next_permutation(comb.begin(), comb.end()));
    
    // for(auto a : vicTable){
    //     for(auto b: a){cout<<b<<" ";}
    //     cout<<endl;
    // }
//     for(int i = 0 ; i<vicTable.size(); i++){
//         for(auto aaa:combRet[i])
//         cout<<aaa+1<<" ";
//         cout<<" : ";
//             for(auto ss : vicTable[i]){
//                 cout << ss<< " ";
//             }
//         cout<<endl;
//     }
    
    int maxIdx = 0 , maxV = 0;
    for(int i = 0 ; i<vicTable.size(); i++){
        if(maxV<vicTable[i][0]){
            maxV=vicTable[i][0];
             maxIdx = i;
        }
            
    }
    
//     for(auto a: combRet[maxIdx])
//         cout<<a+1<< " ";
    for(int i = 0; i<combRet[maxIdx].size() ; i++){
        combRet[maxIdx][i]++;
    }
    return combRet[maxIdx];
}