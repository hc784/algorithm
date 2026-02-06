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
    } // 이거 만든 의미? 끝 글자가 문자일때 다르면 false 
    for(int i = wildcard_index ; i<wildcard_str.size(); i++)
    {

            /*
            // 와일드 카드가 뒤에 남아있는데 파일 인덱스가 끝났다고 브레이크? 그럼 별 안만났을 경우에는 확정 true인데. false 나와야함
            // 이게 true가 나오는 겨웅가있나? 근데 파일 인덱스가 끝나는 경우는 .. 물음표나 문자 만나서 파일인덱스++ 됏을 경우. 이경우는 true 나오는게 맞음
            // 근데 별 만나서 끝까지 파일 인덱스 돌리고 끝나면 ret 을 반환하게 되네.
            // 뒤에 와일드 카드가 남았는데 문자가 끝날 경우는? true가 나온다. 버그 발견
            // 와일드 카드가 남았을 때 그 남은 글자가 별이면 상관없음. 오류가 너무 많은데 이걸 어케 다고치냐.
            인덱스 검사는 필수로 있어야하는데 별일 경우에만 인덱스 검사 넣어두고 ret 반환하게 만들기, 문자가 남아있는데 인덱스가 끝났다? 그럼 false반환, 물음표인데 인덱스 끝났다? false 반환
1
ab*absd*kc*acas*g
1
ababsdwascabsdaskasdkcasdacasdkasdkg
        */
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
            file_index++; /* 지금은 파일명 끝에 파일 인덱스 가있으면 와일드 카드 ? 랑 파일 인덱스가 매치 되지 않아도 브레이크 
            되면서 트루 반환함 oktrue 있으면 ret 반환하고. 
            와일드 카드가 물음표인데 파일명에 글자가 없다? 그럼 펄스가 나와야함. 물음표일때 파일명의 마지막 글자라면, 마지막 글자가 있다면 true. 앞이 다맞앗을 경우에.
            마지막 글자일대늦ㄴ 파일 인덱스 ++ 되몀ㄴ서 파일 네임 사이즈랑 같아지고, 브레이크 되면서 true 반환
            
            */
             // 파일 인덱스가 파일명보다 길어졌지만 아직 남은 와일드 카드가 있으면 false 근데 그 남은 와일드 카드가 *이 아니여야함. 하나남았고 
            //하나 남은게 별이라면 true가 나와야함
            //근데 파일 인덱스도 끝났고, 와일드 카드도 같이 끝났을 경우가 true. 그때는 브레이크
            //근데 와일드 카드에 남은게 있을 때 그게 별 하나가 아니면서(이건 별 안에 코딩 되어있음. 따로 코딩할 필요 x) 파일명에 남은게 없는경우는 제일 위에 코딩하는게 맞는듯.
            //그럼 여기서 
             
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



/*
물음표 생략 가능한지 
물음표 생략 안되게 변경?
변경할거 
1. ? 만났을 때 무조건 하나 뛰는걸로 돼있는데. 이걸 생략이 가능하게 바꿔볼까? 이건 아닌거 같고
2. 생략 불가능하게 바꾸려면
1. 
6
he?p
3
help
heap
helpp
*p*
3
help
papa
hello
*bb*
1
babbbc
t*l?*o*r?ng*s
3
thelordoftherings
tlorngs
tllorrngs
******a
2
aaaaaaaaaab
abcdea
a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a
2
ahfjsdhfjkdshfkjdshfkdsaojajfjaljaflkajflkdsaljflkaflsaffasfa54656454aafasfsdafsaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb
*/