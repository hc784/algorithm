#include <bits/stdc++.h>


using namespace std;
bool flag = false;
bool aa(string a,int index){
    int si = a.size() / 2;
    if(si==0) return true;
    string lefts =a.substr(0,si);
    string rights =a.substr(si+1,si);
    if(a[si]=='0'){
        
       if( lefts[lefts.size()/2] == '1' || rights[rights.size()/2] == '1')
        
        {
          return false;
        
        }
    
    }
        return aa(lefts,index) && aa(rights,index+si+1);
    
    
}
vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(int k = 0 ; k < numbers.size(); k++){
     std::string result = std::format("{:b}", numbers[k]);
        flag=false;
    int n = result.size();
    int i = 1;
    while(n > i-1){
        i=i<<1;
    }
    string temp="";
    int dif = i-1-n;
    while(dif--){
        temp+="0";
    }
    result=temp+result;
    // cout<<result; 
    
    answer.push_back(aa(result, 0));
        
    }
    return answer;

}