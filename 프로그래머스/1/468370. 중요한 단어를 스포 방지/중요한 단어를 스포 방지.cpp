#include <string>
#include <bits/stdc++.h>

using namespace std;
/*
해쉬 세트에 기록.
1. 스포 구간인지 확인.
스포 구간이면 해당 단어를 스포 세트에 기록 후 중요한 단어 +1
스포 세트에 이미 있으면 무시.

아니면 일반 세트에 기록.

스포 구간은 정렬되어 있으니 차례대로 검색.


*/
int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    unordered_set<string> spo, common;
    vector<bool> spoRange(20001,false);
    
    for(auto a : spoiler_ranges){
        for(int i = a[0]; i<= a[1] ; i++){
            spoRange[i] = true;
        }
    }
    // 일반 구간이면
    int startIdx = 0;
    bool spoflag = false;
    for(int i = 0 ; i<=message.size() ; i++){
        if(message[i] == ' ' || i == message.size()){
            if(!spoflag)
            {
               common.insert(message.substr(startIdx, i-startIdx));
            }
            startIdx = i+1;
            spoflag = false;
            continue;
        }
        //스포 구간인지 확인. 
        if(spoRange[i]){ // 스포 구간이면 다음 단어로 넘어가기. 
           spoflag = true; 
            
        }

                    
            // 스포 구간 아닌지 식별 하는 방법. 플래그 두고 공백을 만났을 때 spo flag false면 첫 문자부터 공백 앞까지 일반 세트에 넣기
              
     }
        // for(auto a : common){
        //     cout<<a<<" ";
        // }
    // 스포 구간 확인 : 공백 다음 첫문자 인덱스 기록. 새로운 단어마다 초기화. 스포 구간인지는 매반복마다 확인.
    // 만약 중간에 스포 구간이 포함되어 있으면 첫문자 인덱스부터 끝문자까지 해서 넣는다.
    startIdx = 0;
    for(int i = 0 ; i<message.size() ; i++){

        //스포 구간인지 확인. 
        if(spoRange[i]){ // 스포 구간이면
            // 스포 세트에 없으면 해당 단어를 스포 세트에 기록 후 중요한 단어 +1
                // 단어 범위 찾기. 공백을 만날때까지 인덱스 ++
                
                while(message[i] != ' ' && i != message.size()){
                    i++;
                }
            
            // 단어 구간은 startIdx ~ i-1, substr(startIdx, i-startIdx)
            auto a = spo.insert(message.substr(startIdx, i-startIdx));
            auto it = common.find(message.substr(startIdx, i-startIdx));
            if(a.second && it == common.end()){
                answer++;
                cout<<message.substr(startIdx, i-startIdx)<<endl;
            }
            

            //스포 세트에 이미 있으면 무시.
        }
                if(message[i] == ' '){
                startIdx = i+1;
            }
        
    }
    
    return answer;
}