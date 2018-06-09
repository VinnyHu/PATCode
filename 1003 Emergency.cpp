#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<map>
#include<vector>
#include<cstdio>
#include<stdio.h>
using namespace std;
int G[511][511];
int rescue_team[511];
bool vis[511] = {false};
int d[511];
int INF = 11111111;
int team[511];
int different_path[511];
int N,M,C1,C2;
void Dijkstra(int s)
{
	d[s] = 0;
	different_path[s] = 1;
	team[s] = rescue_team[s];
	for(int i = 0;i < N;i++)
	{
		int u = -1,MIN = INF;
		for(int j = 0;j < N;j++)
		{
			if(vis[j] == false&&d[j] < MIN)
			{
				MIN = d[j];
				u = j;
			}
		}
		if(u == -1)
			return;
		vis[u] = true;
		for(int v = 0;v < N;v++)
		{
			if(vis[v] == false&&G[u][v] != INF)
			{
				if(d[u] + G[u][v] < d[v])
				{
					d[v] = d[u] + G[u][v];
					different_path[v] = different_path[u];
					team[v] = team[u] + rescue_team[v];
				}
				else if(d[u] + G[u][v] == d[v]&&team[v] < team[u] + rescue_team[v])
				{
					team[v] = team[u] + rescue_team[v];
					different_path[v] += different_path[u];
				}
				else if(d[u] + G[u][v] == d[v])
				{
					different_path[v] += different_path[u];
				}
				
			}
		}
	}
}
int main()
{
	scanf("%d%d%d%d",&N,&M,&C1,&C2);
	fill(G[0],G[0] + 511*511,INF);
	fill(d,d+N,INF);
	fill(team,team+N,0);
	fill(different_path,different_path+N,0);
	for(int i = 0;i < N;i++)
	{
		scanf("%d",&rescue_team[i]);
	}
	for(int i = 0;i < M;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		G[a][b] = c;
		G[b][a] = c;
	}
	Dijkstra(C1);
	printf("%d %d\n",different_path[C2],team[C2]);
	return 0;
}
