#include<bits/stdc++.h>
using namespace std;
int main()
{
	queue<int>hp;
	queue<int>lp;
	int n;
	char p,choice;
	do
	{
		cout<<"enter data along with priority[h/l]:";
		cin>>n>>p;
		
		if(p=='H'||p=='h')
			hp.push(n);
		else if(p=='L'||p=='l')
			lp.push(n);
		else
			cout<<"\nassigned wrong priority try again.";
		
		cout<<"\nDo you want to continue[y/n]:";
		cin>>choice;

	}while(choice=='Y'||choice=='y');

	cout<<"\nprocessing data....";
	cout<<"\n\nprocessing high priority queue.....";
	while(!hp.empty())
	{
		cout<<hp.front()<<" ";
		hp.pop();
	}

	cout<<"\n\nprocessing low priority queue.....";
	while(!lp.empty())
	{
		cout<<lp.front()<<" ";
		lp.pop();
	}
}