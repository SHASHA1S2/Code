#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int a[1000007];
int b[1000007];
int main()
{
	int i,j;
	memset(b,1,sizeof(b));
	for(i=1;i<1000007;i++)
	{
		for(j=i;j<1000007;j+=i)
			a[j]++;
	}
	for(i=2;i<1000007;i++)
	{	
		for(j=i+i;j<1000007;j+=i)
			if(a[j] % a[i])	b[j]=0;
	}
	//for(i=2;i<1000007;i++) {cout<<i<<b[i]<<' ';}
	int count=1;
	for(i=7;i<1000007;i++)
	{
		if(b[i] && a[i]>3)
			{
				count++;
				if(count%108==0)
					{cout<<i<<endl;}
							
			}
	}
	return 0;

}
