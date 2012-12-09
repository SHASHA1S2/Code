#include<iostream>
#include<cstdio>

using namespace std;

long long int counting[10005];
int prime[10005];
int isPrime(int n)
{
	if(n==0||n==1)return 0;
	for(int i=2;i*i<=n;i++)
		if(n%i==0)return 0;
	return 1;
}

void compute()
{
for(int i=0;i<=10000;i++)
if(isPrime(i))prime[i]=1;
}
long long int solve(int n)
{
	long long int ans=1;
	for(int j=1;j<=n;j++)
		if(prime[j])
		{
			int t=n;
			int cnt=0;
			while(t)
			{
				t/=j;
				cnt+=t;
			}
			ans*=(2*cnt+1);	
		}
	return ans;
}

int main()
{
	compute();
	int n;
	while(scanf("%d",&n))
	{
		if(n==0)break;
		printf("%lld\n",solve(n));
	}
	return 0;
}
