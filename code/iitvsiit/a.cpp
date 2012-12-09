#include<cstdio>
using namespace std;
int main()
{
long long K,a[2000],b[2000],index[2000],i,temp,j;
scanf("%Ld",&K);
for(i=0;i<K;i++)
{
	scanf("%Ld%Ld",&a[i],&b[i]);
	index[i]=i;
}
for(i=0;i<K;i++)
	for(j=i+1;j<K;j++)
	{
	if((a[j]*b[i]<a[i]*b[j])||((a[j]*b[i]==a[i]*b[j])&&index[i]>index[j]))
	{
		temp=a[i];a[i]=a[j];a[j]=temp;
		temp=b[i];b[i]=b[j];b[j]=temp;
		temp=index[i];index[i]=index[j];index[j]=temp;		
	}
	
	}
for(i=0;i<K;i++)	
	printf("%Ld ",index[i]+1);

return 0;
}
