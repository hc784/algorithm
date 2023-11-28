#include <iostream>
#include <vector>
#include <string>
using namespace std;

int area(vector<int>& height,int depth)
{
    if(depth>=height.size())
    {
        return 0;
    }
    
    int count=1;
    for(int i=depth-1;i>=0&&height[depth]<=height[i];i--)
    {
        count++;
    }
    for(int i=depth+1;i<height.size()&&height[depth]<=height[i];i++)
    {
        count++;
    }
    
    int ret = count * height[depth];
    int temp = area(height, depth+1);
    
    
    return ret>temp ? ret : temp;
}


int main()
{
    int n;
    string ret;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        vector<int> abc(100);
        for(int j=0;j<k;j++)
        {
            int c;
            cin>>c;
            abc.push_back(c);
        }
        ret+=to_string(area(abc,0))+"\n";
    }
    cout<<ret;
    
    return 0;
}
