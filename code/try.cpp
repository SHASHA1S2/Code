#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	
	long long i,t;
	long long n,j=1,k;
	scanf("%lld",&t);
	while(t--)
	{
		long long min,d,tmp;
		scanf("%lld",&n);
		scanf("%lld",&k);
		min=n;
		long long c=k,count=0;
		long long fact=0;
		for(i=(long long)(sqrt(k));i>=2;i--)
		{
			while(c%i==0) {c=c/i;count++;}
			if(k%i==0 && pow(i,count)>fact) {fact=pow(i,count);count=0;}
			
		}
		long long pig=max(c,fact);
		cout<<pig;
		long long sum=0;
		while(n)
		{
			sum+=n/pig;
			n=n/pig;
		}	
		printf("%lld\n",sum);
	}
	return 0;
}




