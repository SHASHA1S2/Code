#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	long long t,n;
	double c;
	cin>>t;
	while(t--)
	{
		cin>>n;
		c=1 - 1.0/n + 1.0/(n*(n+1)) ;
		printf("%.8f\n",c);
	}
return 0;
}
