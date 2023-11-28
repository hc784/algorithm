#include <iostream>
#include <string>
using namespace std;

string reverse(string::iterator& iter)
{  
    char head = *iter++;
    if(head!='x')
    {
        return string(1,head);
    }
    
    string upleft=reverse(iter);
    string upright=reverse(iter);
    string downleft=reverse(iter); 
    string downright=reverse(iter);
    
    return "x"+downleft+downright+upleft+upright;
}

int main()
{
    string ret;
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        string str;
        cin>>str;
        string::iterator iter=str.begin();
        ret+=reverse(iter)+"\n";
        
    }
    cout<<ret;

    
    return 0;
}
