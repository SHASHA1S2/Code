#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
LL mod;

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

int isPrime (int N)
{
	for(int i = 2; i*i <= N ;i++)
		if(N%i==0)
			return false;
			
	return true;

}

int belong(int i)
{
	if(i==3 || i==5 || i==7 || i==10 || i==11 || i==13)
		return true;
	return false;
}

int main()
{
	LL big = 13082761331670030LL;
	int T;
	vector <int > P;
	vector < vector<int> > List(15);
	for(int i = 2 ; i < 45 ; i++)
	{
		if(isPrime(i))
			P.push_back(i);
	}
	
//	for(int i=0; i < P.size() ; i++)
//	{
//		printf("%d ",P[i]);
//	}
	int i,j;
	for(i=0 ; i < P.size() ; i++)
	{
		for(j=1;j<=P[i] ; j++)
			if((j*j*j) % P[i] == 1)
				List[i].push_back(j);
	
	}
	cout<<P.size();
	for(i=0;i<14;i++)
	{
		for(j=0;j<List[i].size(); j++)
			printf("%d ",List[i][j]);
		cout<<endl;
	}
	vector <int> W;
	LL ans=0;
	for( int iter = 0; iter < 729 ;iter ++)
	{
		int temp=iter;
		W.clear();	
		for(i=0;i<14;i++)
		{
			if(belong(i))
				{W.push_back(List[i][temp % 3]);temp/=3;}
			else
				W.push_back(List[i][0]);
		}
//		for(i=0;i<14;i++)
//			cout<<W[i]<<' ';
//		cout<<endl;
		LL p=0;
		for(i=0;i<14;i++)
		{
			LL mul=13082761331670030LL/P[i];
			mod=P[i];
			p+= (W[i] * inverse(mul%mod)*mul);
			p%=big;
//			if(ans<0)
//				printf("Fuck\n");
		}
		
		cout<<p<<endl;
		ans+=p;
		
	}	
	cout<<ans-1<<" = ans\n";
	
}
