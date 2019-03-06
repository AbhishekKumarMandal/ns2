//PROGRAM TO FIND CRC
#include<iostream>
using namespace std;

int main()
{
	int k,n;
	cout<<"enter size of dataword:";
	cin>>k;
	cout<<"enter size of codeword:";
	cin>>n;
	if(n<k)
	{	
		cout<<"codeword size must be greater than dataword.";
		exit(0);
	}
	else
	{
		char dataword[n],codeword[n],divisor[n-k+1],arr[n],quotient[k];
		cout<<"divisor size will be: "<<(n-k+1);
		cout<<"enter dataword:";
		cin>>dataword;
		cout<<"enter divisor:";
		cin>>divisor;
		for(int i=k;i<n;i++)
			dataword[i]='0';
		cout<<"dividend:"<<dataword;
		for (int i=0;i<n;i++)
			arr[i]=dataword[i];
		
		int temp;
		for(int i=0;i<k;i++)
		{
			temp=i;
			if(arr[temp]=='1')
			{
				quotient[temp]='1';
				for(int j=0;j<(n-k+1);j++)
					if(divisor[j]==arr[temp])
						arr[temp]='0';
					else
						arr[temp]='1';
					temp+=1;
			}
			else
				quotient[temp]='0';
		}
		cout<<"\nquotient: "<<quotient;
		cout<<"\nremainder:";
		for(int i=k;i<n;i++)
		{
			cout<<arr[i];
			dataword[i]=arr[i];
		}
		cout<<"\ncodeword:"<<dataword;
		char choice;
		cout<<"\nwant err detection[y/n]:";
		cin>>choice;
		if(choice=='Y'||choice=='y')
		{
			for(int i=0;i<n;i++)
				arr[i]=dataword[i];
			
			int pos;char err;
			cout<<"\nenter err data along with position:";
			cin>>err>>pos;
			if( pos<=0 || pos>n)
				cout<<"enter wrong position try again.";
			else if((err!='0' && err!='1'))
				cout<<"enter wrong data try again.";
			else
			{
				arr[pos-1]=err;
				cout<<"err data:"<<arr;

				for(int i=0;i<k;i++)
				{
					temp=i;
					if(arr[temp]=='1')
					{
						quotient[temp]='1';
						for(int j=0;j<(n-k+1);j++)
							if(divisor[j]==arr[temp])
								arr[temp]='0';
							else
								arr[temp]='1';
							temp+=1;
					}
					else
						quotient[temp]='0';
				}
				cout<<"\nquotient: "<<quotient;
				cout<<"\nremainder:";
				for(int i=k;i<n;i++)
					cout<<arr[i];
			}

		}
	}
	return 0;
}
