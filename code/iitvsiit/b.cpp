#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
	long long mid1,T,a,b,mid,c[100000],M,i,ans,iter;
	scanf("%Ld%Ld",&T,&M);
	for(i=0;i<T;i++)
	{	
		scanf("%Ld",&c[i]);		
	}
	a=0;b=pow(10,10);
	iter=0;
	while(a!=b)
	{
		
		//printf("%Ld %Ld %Ld\n",a,b,mid);
		mid=(a+b)/2;
		ans=1;
		mid1=mid;
		for(i=0;i<T;i++)
		{
			if(mid1>=c[i])
				mid1=mid1-c[i];
			else
				{ans++;mid1=mid;i--;}
			if(ans>M)
				break;
		}
		if(i==T)
			b=mid;
		else
			a=mid+1;
	}
	printf("%Ld\n",a);
	return 0;
}
