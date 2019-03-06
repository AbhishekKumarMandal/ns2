#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define MIN(x,y) (x>y)? y:x

using namespace std;

int main()
{
	int capacity, rate, i=0;
	char choice;
	int inp[100];
	cout<<"\nenter bucket size:";
	cin>>capacity;
	cout<<"\nenter output rate:";
	cin>>rate;
	do
	{
		cout<<"\nenter packet comming at second"<<i+1<<": ";
		cin>>inp[i];

		i++;

		cout<<"\ndo you want to continue[y/n]:";
		cin>>choice;

	}while(choice=='Y' || choice=='y');

	cout<<"\nsecond"<<"\treceived"<<"\tsend"<<"\tdropped"<<"\tremained\n";

	int drop=0,remain=0,send;

	for(int j=0;remain || j<i;j++)
	{
		cout<<j+1;
		cout<<"\t"<<inp[j];
		send=MIN(rate,(inp[j]+remain));
		cout<<"\t"<<send;
		remain=(inp[j]+remain)-send;
		if(remain>0)
		{
			if(remain>capacity)
			{
				drop=remain-capacity;
				remain=capacity;
			}
			else
				drop=0;
		}
		else
		{
			remain=0;
			drop=0;
		}
		cout<<"\t"<<drop<<"\t"<<remain<<"\n";
	}

}