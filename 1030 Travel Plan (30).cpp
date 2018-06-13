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
using namespace std;
int N,M,S,D;
int cost[511];
typedef pair<int,int> par;
priority_queue<par,vector<par> ,greater<par> > pir;
int d[511];
int path[511];
bool vis[511] = {false};
int INF = 99999999;
struct Node
{
	int number;
	int distance;
	int cost;

};
vector<Node>G[511];
void DFS(int s,int v)
{
	if(v == s)
	{
		printf("%d ",s);
		return;
	}
	DFS(s,path[v]);
	printf("%d ",v);
}
int main()
{
	
	scanf("%d%d%d%d",&N,&M,&S,&D);
	fill(d,d+N,INF);
	fill(cost,cost+N,INF);
	for(int i = 0;i<N;i++)
	{
		path[i] = i;
	}
	for(int i = 0;i < M;i++)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		struct Node nod1 = {b,c,d};
		struct Node nod2 = {a,c,d};
		G[a].push_back(nod1);
		G[b].push_back(nod2);
	}
	d[S] = 0;
	cost[S] = 0;
	pir.push(make_pair(d[S],S));
	while(!pir.empty())
	{
		par u = pir.top();
		pir.pop();
		int num = u.second;
	
		if(vis[num])
		{
			continue;
		}
		vis[num] = true;
		for(int i = 0;i<G[num].size();i++)
		{
			Node temp_nod = G[num][i];
			if(vis[temp_nod.number] == false)
			{
				if(temp_nod.distance + d[num] < d[temp_nod.number])
				{
					d[temp_nod.number] = temp_nod.distance + d[num];
					pir.push(make_pair(d[temp_nod.number],temp_nod.number));
					path[temp_nod.number] = num;
					cost[temp_nod.number] = temp_nod.cost + cost[num];
					
				}	
				else if(temp_nod.distance + d[num] == d[temp_nod.number])
				{
					if(temp_nod.cost + cost[num] < cost[temp_nod.number])
					{
						path[temp_nod.number] = num;
						cost[temp_nod.number] = temp_nod.cost + cost[num];
						
					}
				}
			}
		}
	
	}

	DFS(S,D);
	printf("%d %d",d[D],cost[D]);
	return 0;
}
