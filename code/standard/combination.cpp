#include<cstdio>
#include<iostream>

long long comb[62][35];
long long combinit()
{
	long long i,j;
	for(i=0;i<62;i++)
	{
		comb[i][0]=1;
	}
	for(j=1;j<32;j++)
	{
		for(i=1;i<62;i++)
		{
			comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
		}
	}
}

using namespace std;

long long a[100];
int main()
{
	combinit();
	//cout<<comb[60][30];
	long long i=2,T,N,count;
	a[1]=1;a[2]=1;
	for(i=3;i<64;i++)
	{
		if(i%2==1) a[i]=a[i-1];
		else a[i]=a[i-1]+comb[i-1][(i-1)/2];
	}
	cin>>T;
	while(T--)
	{
		cin>>N;
		count=0;
		while(N!=1)
		{
			count++;N=N/2;
		}
		cout<<a[count]<<endl;
	}
//	cout<<a[60];
	return 0;
}
