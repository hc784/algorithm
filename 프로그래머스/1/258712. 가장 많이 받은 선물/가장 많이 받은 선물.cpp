#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <iostream>
using namespace std;
/*
1. 두사람이 선물을 주고 받은 기록.
두사람 사이에 더 많은 선물을 준 사람이 받음.

2. 선물 지수 : 자신이 준 선물 수 - 받은 선물 수
3. 기록이 없거나 같다면 선물 지수가 큰 사람이 선물을 받음.

4. 선물지수도 같으면 주고 받지 않음.

구할 것 가장 많은 선물의 수.

문자열 파싱해서 리스트에 넣기.
리스트는? 리스트 말고 해싱?
a["muzi"] = 갯수

다음달 받을 수를 예측해야함.
두 사람 사이의 관계를 통해 받는 값 예측.
필요한 것.
두 사람 사이의 선물 관계.

1. 2차원 배열로 나타내기.
2. 2차원 배열 기반으로 선물 수 예측하기.
예측하는 알고리즘.
한명 한명 돌아가면서 선물 받기.

2차원 배열로 나타내는 방법.
1. 숫자로 바꾸기 이름.
2. 이름 바꾼거 gifts에서 숫자로 바꾸고,
*/

vector<string> split(string s){
    
    stringstream ss(s);
    vector<string> vec;
    string temp;
    
    while(ss>>temp) 
    {
        vec.push_back(temp);
    }
    
    return vec;
}


int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int n = friends.size();
    vector<vector<int>> data(n,vector<int>(n,0));
    
    unordered_map<string,int> a;
    for(int i = 0 ; i<n ; i++){
        a[friends[i]] = i;
    }
    
    for(int i = 0 ; i<gifts.size() ; i++){
        vector<string> vec = split(gifts[i]);
        data[a[vec[0]]][a[vec[1]]]++;
    }
    // 준 선물 수는 2차원 배열에서 행에 있는 모든 값을 더한 수.
    // 받은 선물 수는 열 모든 값 더한 수
    // 선물 지수 구하기.
    
    vector<int> give(n,0), get(n,0), num(n,0);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            give[i]+=data[i][j];
            get[j]+=data[i][j];
    }}
                    
    for(int i = 0 ; i < n ; i++){
        num[i] = give[i] - get[i];
    }
    vector<int> ret(n,0);
    for(int i = 0; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            //cout<<data[i][j]<<" ";
            if(i==j) continue;
            if( (data[i][j] == 0 && data[j][i] == 0 ) || data[i][j] == data[j][i] )
            {
                if(num[i]==num[j]) continue;
                if(num[i]>num[j]) ret[i]++;
                else ret[j]++;
            }
            else if(data[i][j] > data[j][i]){
                ret[i]++;
            }
            else ret[j]++;
        }
    }
    for(int i = 0 ; i < n ; i++){
        cout<<ret[i];}
    auto it = max_element(ret.begin(),ret.end());
    answer = *it;
    return answer;
}