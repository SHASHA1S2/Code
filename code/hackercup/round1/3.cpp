#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	long long a[1010],array[1010];
	long long T,i,sum1,m,length;
	scanf("%lld",&T);
	long long t=T;
	long long p=4207849484;
	while(T--)
	{
		scanf("%lld",&m);
		char c;
		scanf("%c",&c);
		scanf("%c",&c);
		i=0;		
		while(c!='\n')
		{
			if(c-'0'<10&&c-'0'>=0)
				array[i++]=c-'0';
			scanf("%c",&c);
		}	
		length=i-1;
		for(i=0;i<1010;i++)
			a[i]=0;
		if(array[length]<=m&&array[length]>=1)
			a[length]=1;
		if(array[length-1]<=m && array[length]<=m &&array[length]>=1 && array[length-1]>=1)
			a[length-1]++;
		if(array[length-1]*10+array[length]<=m && array[length-1]*10+array[length]>0)
			a[length-1]++;
		if(array[length-1]==0) a[length-1]=0;
		if(array[length-2]<=m && array[length-2]>0)
			a[length-2]+=a[length-1];
		if(10*array[length-2]+array[length-1]<=m  && 10*array[length-2]+array[length-1]>0)
			a[length-2]+=a[length];
		if(100*array[length-2]+10*array[length-1]+array[length]<=m && 100*array[length-2]+10*array[length-1]+array[length]>0)
			a[length-2]+=1;
		if(array[length-2]==0) a[length-2]=0;
		for(i=length-3;i>=0;i--)
		{
			sum1=0;
			if(array[i]<=m && array[i]>0)
				sum1+=a[i+1];
			if(10*array[i]+array[i+1]<=m && 10*array[i]+array[i+1]>0)
				sum1+=a[i+2];
			if(100*array[i]+10*array[i+1]+array[i+2]<=m  && 100*array[i]+10*array[i+1]+array[i+2]>0)
				sum1+=a[i+3];
			a[i]=sum1 % p;
			if(array[i]==0)
				a[i]=0;
		}	
		//for(i=0;i<=length;i++)
		//	prlong longf("%lld ",a[i]);
		printf("Case #%lld: %lld \n",t-T,a[0]);
	}
	return 0;
}
