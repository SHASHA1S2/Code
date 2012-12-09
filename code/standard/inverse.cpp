#include<cstdio>
#include<iostream>

using namespace std;
typedef long long LL;
LL mod=1000000007LL;

LL inverse(LL n)
{
	LL a=mod,temp;
	LL b=n,c00,d00,c11,d11,c01,q,d01,d10,c10;
	c00=1;c01=0;c10=0;c11=1;
	while(b!=0)	
	{
		q=a/b;
		d00=c10;d01=c11;d10=c00-q*c10;d11=c01-q*c11;
		c00=d00;c01=d01;c11=d11;c10=d10;
		temp=b;
		b=a%b;
		a=temp;
	}
	while(c01<mod)
		c01+=mod;
	return c01%mod;
}
LL fact[2000009];
//LL rev[1000009];
void init()
{
	fact[0]=1;
	for (int i=1;i<2000009;i++)
		fact[i]=(fact[i-1]*i)%mod;
	
}

LL solve(LL n)
{
	LL p=1;
	p*=fact[2*n];
	p=(p*inverse(fact[n]))%mod;
	p=(p*inverse(fact[n-1]))%mod;
	p=(p*inverse(2))%mod;
	return p;
}
int main()
{
	LL n,t;
	cin>>t;
	init();
	while(t--){
		cin>>n;
		cout<<solve(n)<<endl;
	}
return 0;
}
