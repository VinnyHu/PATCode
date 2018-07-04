#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<map>
#include<vector>
#include<cstdio>
#include<stdio.h>
#include<queue> 
#include<cmath>
using namespace std;
int C,N,S,M;
typedef pair<int,int>par;
priority_queue<par,vector<par>,greater<par> > pir;
struct Node
{
	int number;
	int time;	
};
vector<int> pre[511];
int bike[505];
vector<Node> nod[505];
int d[505];
int INF = 99999999;
bool vis[505] = {false};
vector<int>tempath;
vector<int>path;
int bringback = INF;
int takesend = INF;
int tempbike[505];
void DFS(int v)
{
	if(v == 0)
	{
		tempath.push_back(v);
		int back = 0;
		int send = 0;
		int num = tempath.size();
		int tempindex = 0;
		for(int i = num - 2;i >= 0;i--)
		{
			tempbike[tempindex] = bike[tempath[i]];
			tempindex++;
		}
		for(int i = 0;i <= num-2;i++)
		{
			if(tempbike[i] < 0)
			{
				int temp = tempbike[i];
				int j = i + 1;
				while(j <= num-2&&temp<0)
				{
					if(tempbike[j] > 0)
					{
						if(tempbike[j] >= abs(temp))
						{
							tempbike[j] += temp;
							temp = 0;
						}
						else
						{
							temp += tempbike[j];
							tempbike[j] = 0;
						}
					}
					j++;
				}
				tempbike[i] = temp;
			}
		}
		for(int i = 0;i <= num-2;i++)
		{
			if(tempbike[i] > 0)
			{
				send += tempbike[i];
			}
			else if(tempbike[i] < 0)
			{
				back += tempbike[i];
			}
		}
		if(send < takesend)
		{
			takesend = send;
			path = tempath;
			bringback = abs(back);
		}
		else if(send == takesend)
		{
			if(abs(back) < bringback)
			{
				takesend = send;
				path = tempath;
				bringback = abs(back);
			}
		}
		tempath.pop_back();
		return;
	}
	tempath.push_back(v);
	for(int i = 0;i < pre[v].size();i++)
	{
		DFS(pre[v][i]);
	}
	tempath.pop_back();
}
int main()
{
	scanf("%d%d%d%d",&C,&N,&S,&M);
	int perfect = C / 2;
	fill(d,d+505,INF);
	
	for(int i = 1;i <= N;i++)
	{
		scanf("%d",&bike[i]);
		bike[i] = perfect - bike[i];
	}
	
	for(int i = 0;i < M;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		struct Node n1 = {a,c};
		struct Node n2 = {b,c};
		nod[a].push_back(n2);
		nod[b].push_back(n1);
	}
	d[0] = 0;
	pir.push(make_pair(d[0],0));
	while(!pir.empty())
	{
		par u = pir.top();
		pir.pop();
		int num = u.second;
		if(vis[num] == true)
		{
			continue;
		}
		vis[num] = true;
		for(int i = 0;i<nod[num].size();i++)
		{
			Node temp_node = nod[num][i]; 
			if(vis[temp_node.number] == false)
			{
				if(d[temp_node.number] > d[num] + temp_node.time)
				{
					d[temp_node.number] = d[num] + temp_node.time;
					pir.push(make_pair(d[temp_node.number],temp_node.number));
					pre[temp_node.number].clear();
					pre[temp_node.number].push_back(num);	
				}
				else if(d[temp_node.number] == d[num] + temp_node.time)
				{
					pre[temp_node.number].push_back(num);
				}
			}
		}
	}
	DFS(S);
	cout<<takesend<<" ";
	for(int i = path.size()-1;i > 0;i--)
	{
		cout<<path[i]<<"->";
	}
	cout<<path[0]<<" "<<bringback<<endl;
	return 0;
}
