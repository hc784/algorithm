#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool wildcard(string wildcard_str, string FileName , int wildcard_index , int file_index)
{
    bool ret=false;
    bool okstar=false;

    if(wildcard_str[wildcard_str.size()-1]!='*'&&wildcard_str[wildcard_str.size()-1]!='?'&&wildcard_str[wildcard_str.size()-1]!=FileName[FileName.size()-1])
    {
        return false;
    } //  끝 글자가 문자일때 다르면 false 
    for(int i = wildcard_index ; i<wildcard_str.size(); i++)
    {

           
        if(wildcard_str[i]=='*')  // 두번째 경우 파일명에 문자가 있는데 와일드 카드가 끝난경우
        {
            
            if(i+1==wildcard_str.size()) 
            {
                if(okstar) return ret;
                else return true;
            } // i+2가 wildcard size보다 클경우에는 어케됨?
            okstar=true;
            while(file_index!=FileName.size()) 
            {
                if(wildcard_str[i+1]==FileName[file_index++]||wildcard_str[i+1]=='?') 
                {
                    ret=ret||wildcard(wildcard_str,FileName, i+2, file_index); 
                } 
            }
            if(file_index >= FileName.size()) 
            break; 
            
        }

        else if(wildcard_str[i]=='?') 
        {
            if(FileName.size()-1<file_index)
                return false; // 파일명에 남은 글자가 없는데 물음표를 만났을 경우
            file_index++; 
             
        }
        
        else 
        {
            if(FileName.size()-1<file_index)
                return false; // 파일명에 남은 글자가 없는데 문자를 만났을 경우 false
                
            if(wildcard_str[i]==FileName[file_index])
            {
                file_index++;
            }
            else return false;
        }
        
        if(i+1==wildcard_str.size()&&FileName.size()>file_index)
        {
            return false;   
        }
    }
    if(okstar) return ret;
    else return true;
}
struct cmp{
    bool operator()(string a, string b)
    {
        if(a.compare(b)<0) return false; 
        else return true;
        
    }
};

bool unique_cmp(char& first, char& last)
{
    if(first=='*'&&last=='*')
    {
        return true;
    }
    else return false;
}


int main()
{
    int n;
    cin>>n;
    vector<string> ans(0);
    while(n--)
    {
        priority_queue<string,vector<string>,cmp> answer;
        string wildcard_str;
        cin>>wildcard_str;
        wildcard_str.erase(unique(wildcard_str.begin(),wildcard_str.end(),unique_cmp),wildcard_str.end());

        int num;
        cin>>num;
        
        vector<string> FileName(num);
        for(int i=0; i<num; i++)
        {
            cin>>FileName[i];
        }
        
        for(int i=0;i<num;i++)
        {
            if(wildcard(wildcard_str, FileName[i],0,0))
            answer.push(FileName[i]);
        }
        int sizenum= answer.size();
        for(int i=0;i<sizenum;i++)
        {
            ans.push_back(answer.top()); 
            answer.pop();
        }
    }
    
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<endl;
        
    

    return 0;
}
