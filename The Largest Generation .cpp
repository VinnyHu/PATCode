#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
struct node
{
	int father;
	int generation;	
} Member[200];
int main()
{
	int N,M;
	cin>>N>>M;
	int i = 0;
	while(M--)
	{
		int father,childnum,child;
		cin>>father>>childnum;
		while(childnum--)
		{
				cin>>child;
				Member[child].father = father;
		}
	}
	Member[1].generation = 1;
	
	for(int i = 1;i<=N;i++)
	{
		for(int j = 2;j<=N;j++)
		{
			if(Member[Member[j].father].generation == i)
			{
				Member[j].generation = Member[Member[j].father].generation + 1;
			}
		}
	}
	int count = 0;
	int generation = 0;
	for(int i = 1;i<=N;i++)
	{
		int temp = 0;
		for(int j = 1;j<=N;j++)
		{
			if(Member[j].generation == i)
			{
				temp++;
			}
		}
		if(temp > count)
		{
			count = temp;
			generation = i;
		}
		
	}
	cout<<count<<" "<<generation<<endl;
	return 0;
}
