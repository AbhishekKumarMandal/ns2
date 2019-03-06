#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,src,min,u;
	cout<<"no of vertices:";
	cin>>n;
	int cost[n][n];
	int d[n],visited[n];
	cout<<"\nenter cost matrix:";
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>cost[i][j];

	cout<<"enter source vertex:";
	cin>>src;

	for(int i=1;i<=n;i++)
	{
		visited[i]=0;
		d[i]=cost[src][i];
	}

	visited[src]=1;
	d[src]=0;

	for(int j=2;j<=n;j++)
	{
		min=999;
		for(int i=1;i<=n;i++)
		{
			if(!visited[i])
			{
				if(d[i]<min)
				{
					min=d[i];
					u=i;
				}
			}
		}

		visited[u]=1;

		for(int k=1;k<=n;k++)
		{
			if(cost[u][k]!=999 && visited[k]==0)
			{
				if(d[k]>d[u]+cost[u][k])
					d[k]=d[u]+cost[u][k];
			}
		}
	}

	for(int i=1;i<=n;i++)
	{
		if(i!=src)
			cout<<"shortest distance from "<<src<<" to"<<i<<" is: "<<d[i]<<"\n";
	}

	return 0;
}