#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> height(0);

int fence(int left, int right)
{
    int mid = (left + right) / 2;
    if(left==right)
    {
        return height[left];
    }
    
    int first = fence(left,mid);
    int second = fence(mid +1 , right);
    int maxArea = max(first,second);
    
    int min_height = min(height[mid],height[mid+1]);
    int temp = min_height * 2; 
    int tempLeft = mid; int tempRight = mid+1;
    
    maxArea = max(maxArea,temp);
    
    
    while(tempLeft!=left && tempRight!=right) // !(tempLeft==left && tempRight==right)
    {
        if(height[tempLeft-1]>height[tempRight+1])
        {
            tempLeft--;
            min_height=min(min_height,height[tempLeft]);
            temp=max(temp,min_height*(tempRight-tempLeft+1));
        }
        else 
        {
            tempRight++;
            min_height=min(min_height,height[tempRight]);
            temp=max(temp,min_height*(tempRight-tempLeft+1));
        } 
    }
    
    if(tempLeft==left&&tempRight!=right)
    {   
        while(tempRight!=right)
        {
            tempRight++;
            min_height=min(min_height,height[tempRight]);
            temp=max(temp,min_height*(tempRight-tempLeft+1));  
        }
    }
    else if(tempLeft!=left&&tempRight==right)
    {
        while(tempLeft!=left)
        {
            tempLeft--;
            min_height=min(min_height,height[tempLeft]);
            temp=max(temp,min_height*(tempRight-tempLeft+1));
        }
            
    }
    
    return maxArea=max(maxArea,temp);
    
    
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
        height.clear();
        for(int j=0;j<k;j++)
        {
            int c;
            cin>>c;
            height.push_back(c);
        }
        ret+=to_string(fence(0,k-1))+"\n";
    }
    cout<<ret;

    return 0;
}
