#include <iostream>
using namespace std;

int result[20];
bool check[20];
int count=0;
int a(int depth,int N,int* pair,int pair_size)
{
	if(depth==N/2)
	{
		int chek=0;
		for(int i=0;i<N/2;i++)
		{
			for(int j=0;j<pair_size/2;j++)
			{
				if(result[i*2]==pair[j*2]&&result[i*2+1]==pair[j*2+1])
				{
					chek++;
				}
			}
		}
		if(chek==N/2)
		::count++;
		
		return 0;
	}
	
	int first;
	for(int i=0;i<N;i++)
	{
		if(!check[i])
		{
			first=i;
			
			check[i]=true;
			break;
		}
	}
	result[depth*2]=first;
	for(int i=1;i<N;i++)
	{
		if(!check[i])
		{
			result[depth*2+1]=i;
			check[i]=true;
			a(depth+1,N,pair,pair_size);
			check[i]=false;
		}
		if(i==N-1)
				check[first]=false;
	}
	return ::count;
}

int main()
{
	int test_case,num,friends_pair;
	cin>>test_case;
	for(int k=0;k<test_case;k++)
	{
		::count=0;
		cin>>num>>friends_pair;
		int* pair=new int[friends_pair*2];
		for(int i=0;i<friends_pair*2;i++)
		{
			cin>>pair[i];
		}
		for(int i=0;i<friends_pair;i++)
		{
			if(pair[i*2]>pair[i*2+1])
			{
				int temp=pair[i*2];
				pair[i*2]=pair[i*2+1];
				pair[i*2+1]=temp;
			}
		}
		cout<<a(0,num,pair,friends_pair*2)<<endl;
        delete[] pair;
	}
	
	return 0;	
}
