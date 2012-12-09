#include<cstdio>
#include<iostream>
#include<string>
#include <algorithm>
#include<utility>
#include<cmath>

bool primes[10000009];
int fact[] = {1,1,2,6,24,120,720,5040};
void seive()
{
	int max=10000009;
	int i,j;
	for(i=0;i<max;i++)
	{
		primes[i]=true;
	}
	primes[1]=false;
	for(j=4;j<max;j+=2)
	{
		primes[j]=false;
	}
	for(i=2;i<3163;i++)
	{
		if(primes[i])
		{
			for(j=i*i;j<max;j+=2*i)
			{
				primes[j]=false;
			}
		}
	}
}
int Value[8];  	// 1 to 7 are digits
void perm(int N)
{
	int i = N - 1;
	int temp;
	while (Value[i-1] >= Value[i]) 
		i = i-1;
	int j = N;
	while (Value[j-1] <= Value[i-1]) 
		j = j-1;

	//swap(i-1, j-1);    // swap values at positions (i-1) and (j-1)
	temp=Value[i-1];Value[i-1]=Value[j-1];Value[j-1]=temp;
	i++; j = N;
	while (i < j)
	{
		temp=Value[i-1];Value[i-1]=Value[j-1];Value[j-1]=temp;
		i++;
		j--;
	}
}

long long generate(int N)
{
	int i;
	long long ans=0;
	for(i=0;i<N;i++)
	{
		ans=ans*10 + Value[i];
	}
	return ans;
}
using namespace std;

int main()
{
	long long i;
	long long T,N,count,j;
	seive();
	cin>>T;
	while(T--)
	{
		scanf("%lld",&N);
		count=0;
		while(N)
		{
			Value[count++]=N%10;
			N=N/10;
		}
		sort(Value,Value+count);
		//for(i=0;i<count;i++)	cout<<Value[i]<<' ';
		long long ans=0;
		long long f=fact[count];
		for(i=0;i<count;)	
		{
			for(j=i+1;j<count;j++)
				if(Value[j]!=Value[i])	break;
			f=f/fact[j-i];
			i=j;
		}
		for(i=0;i<f;i++)
		{		
			//cout<<generate(count)<<' ';
			if(primes[generate(count)] && Value[0]!=0)
				ans++;
			perm(count);			
		}
		printf("%lld\n",ans);
	}

return 0;
}
