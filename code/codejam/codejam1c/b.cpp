#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef struct boo
{
	int x;
	int types;
}boo;
boo a[100];
boo b[100];

int T,N,M;
int ans(int i,int j)
{
	//cout<<'('<<i<<j<<") ";
	if(i==N)
		return 0;
	if(j==M)
		return 0;
	int c=0;
	if(a[i].types==b[j].types)
	{
		if(a[i].x>b[j].x)
		{  c=b[j].x;b[j].x=0;a[i].x-=c;return c+ans(i,j+1);  }
		else
		{  c=a[i].x;a[i].x=0;b[j].x-=c;return c+ans(i+1,j);  }	
	}
	else
		return max(ans(i,j+1),ans(i+1,j));

}

int main()
{
	int i,j;	
	cin>>T;
	while(T--)
	{
		cin>>N>>M;
		for(i=0;i<N;i++)
			cin>>a[i].x>>a[i].types;
		for(i=0;i<M;i++)
			cin>>b[i].x>>b[i].types;
		cout<<ans(0,0);

	}
}
