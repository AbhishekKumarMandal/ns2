#include<bits/stdc++.h>
using namespace std;
struct vertex
{
	int distance;
	int parent;
};

int main()
{
	int n,src;
	cout<<"enter the no.of vertices:";
	cin>>n;
	int cost[n][n];
	cout<<"\nenter the cost matrix:";
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>cost[i][j];
	struct vertex s[n];
	for(int i=1;i<=n;i++)
		s[i].distance=999;
	cout<<"\nenter the source vertex:";
	cin>>src;
	s[src].distance=0;
	s[src].parent=src;

	int u,v;

	for(int k=1;k<=(n-1);k++)
	{
		for(int i=1;i<=n;i++)
		{
			u=i;
			for(int j=1;j<=n;j++)
			{
				v=j;
				if(u!=v && cost[u][v]!=999)
				{
					if(s[v].distance > s[u].distance+cost[u][v])
					{
						s[v].distance=s[u].distance+cost[u][v];
						s[v].parent=u;
					}
				}
			}
		}
	}

	//check for -ve cycles

	int old;
	for(int i=1;i<=n;i++)
		{
			u=i;
			for(int j=1;j<=n;j++)
			{
				v=j;
				if(u!=v & cost[u][v]!=999)
				{
					old=s[v].distance;
					if(s[v].distance > s[u].distance+cost[u][v])
					{
						s[v].distance=s[u].distance+cost[u][v];
						s[v].parent=u;
					}
					if(old>s[v].distance)
					{
						cout<<"\ngraph contains -ve cycles can't proceed...";
						exit(0);
					}
				}
			}
		}

	cout<<"\nvertex   distance   parent\n";
	for(int i=1;i<=n;i++)
		cout<<" "<<i<<"    "<<s[i].distance<<"    "<<s[i].parent<<"\n";
}