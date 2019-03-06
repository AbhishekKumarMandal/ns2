#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int main()
{
	int dividend[50],divisor[50],quotient[20],remainder[20],arr[50]={0},i,j,temp,n,k;
	char choice;
	printf("enter dataword size:");
	scanf("%d",&k);

	printf("\nenter codeword size:");
	scanf("%d",&n);

	if(n<=k)
	{
		printf("\ncodeword must be greater than dataword...\n");
		exit(0);
	}

	printf("\ndivisor size will be: %d",n-k+1);

	printf("\nenter the dataword\n");
	for(i=0;i<k;i++)
		scanf("%d",&dividend[i]);
	printf("\nenter the divisor\n");
	for(i=0;i<(n-k+1);i++)
	{
		scanf("%d",&divisor[i]);
	}
	for(i=0;i<(n-k);i++)
	{
		dividend[k+i]=0;
	}

	printf("\narray: ");
	for(int i=0;i<n;i++)
	{
		arr[i]=dividend[i];
		printf("%d",arr[i]);
	}
	
	for(i=0;i<k;i++)
	{
		temp=i;
		if(arr[i]==1)
		{
			quotient[i]=1;
			for (j=0;j<(n-k+1);j++)
			{
				if (arr[temp]==divisor[j]) // doing xor operatiton.
					arr[temp]=0;
				
				else
					arr[temp]=1;
				
				temp=temp+1;
			}
		}
		else
			quotient[i]=0;
	}
	printf("\nthe quotient is: ");
	
	for(i=0;i<k;i++)
		printf("%d",quotient[i]);

	printf("\nand the remainder is: ");

	for(int i=k;i<n;i++)
	{
		printf("%d",arr[i]);
		dividend[i]=arr[i];
	}
	printf("\ncode word generated:");
	for(i=0;i<n;i++)
	{
		printf("%d",dividend[i]);
		arr[i]=dividend[i];
	}


cout<<"\nwant error detection [y/n]:";
cin>>choice;
int pos,err;
if(choice=='y'|| choice=='Y')
{
	printf("enter position and error data:");
	scanf("%d%d",&pos,&err);
	if(pos<=0 || pos>n)
		printf("\nwrong position try again..\n");
	else if (err!=0 && err!=1)
		printf("\nenter wrong error data try again..\n");
	else
	{
		arr[pos-1]=err;
		cout<<"\narray:";
		for(int i=0;i<n;i++)
			cout<<arr[i];
		cout<<"\n";
		for(int i=0;i<k;i++)
		{
			temp=i;
			if(arr[i]==1)
			{
				quotient[i]=1;
				for(int j=0;j<(n-k+1);j++)
				{
					if(arr[temp]==divisor[j])
						arr[temp]=0;
					else
						arr[temp]=1;
					
					temp+=1;
				}
			}
			else
				quotient[i]=0;
		}

		printf("\nthe quotient is: ");
		for(int i=0;i<k;i++)
			printf("%d",quotient[i]);

		printf("\nand the remainder is: ");
		for(int i=k;i<n;i++)
			printf("%d",arr[i]);

	}
 }
 return 0;
}