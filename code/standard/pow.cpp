#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
long long  visited[100009];

long long  N;
long long  ans;
long long  mod=1000000007;
long long lol;
long long  pow(long long  x,long long  n)
{
	long long  p=x;
	long long  ans1=1;
	while(n)
	{
		if(n%2==1)
			ans1=(ans1*p)%mod;
		p=(p*p)%mod;
		n/=2;
	}
	return ans1;
}

long long  dfs(long long  i)
{
	if(visited[i])
		return 0;
	visited[i]=1;

	if(i<=N/2)	
		dfs(2*i);
	else
		dfs((i-N/2)*2-1);	
}

int  main()
{
	long long  T;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&N);
		memset(visited,0,sizeof(visited));
		ans=0;
		for (int i=1;i<=N;i++)
		{
			if (!visited[i])
			{
				dfs(i);
				ans++;
			}
		}
		//dfs(1);
		printf("%lld\n",pow(26,ans));
	}

	return 0;
}
