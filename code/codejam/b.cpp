#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
long long a[2000000];
long long b[25];
using namespace std;

void print(long long x,long long y)
{
long long count=0;
while(x)
{
	if(x%2)
		cout<<b[count]<<' ';
	x=x/2;count++;
}
cout<<endl;
count=0;
while(y)
{
	if(y%2)
		cout<<b[count]<<' ';
	y=y/2;count++;
}
cout<<endl;
}
int main()
{
	long long T;
	cin>>T;
	long long t=T;
	while(T--)
	{
	cout<<"Case #"<<t-T<<":"<<endl;
	long long full=2000000;
	long long N,i,sum,count,n;
	cin>>N;
	for(i=0;i<N;i++)
		cin>>b[i];
	sort(b,b+N);
	for(i=0;i<full;i++)
		a[i]=0;
	for(i=0;i<1<<19;i++)
	{
		n=i;
		sum=0;
		count=0;
		while(n)
		{
			if(n%2)
				sum=sum+b[count];
			n=n/2;count++;
		}	
		if(a[sum]!=0)
			{print(i,a[sum]);break;}
		else
		a[sum]=i;

	}
	if(i==1<<19)
		cout<<"Impossible"<<endl;
	}
return 0;
}
