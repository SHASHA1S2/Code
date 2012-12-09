#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	long long k,b,n,t;
	cin>>k>>b>>n>>t;
	long long ye=0;
	long long in=1;
	while(in<=t)
	{
		in=k*in+b;
		ye++;	
	}
	ye--;
	cout<<max(0LL,n-ye)<<endl;
	
	return 0;	
}
