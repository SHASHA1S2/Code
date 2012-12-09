#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int T,i,t,a[26];
	char c;
	scanf("%d",&T);
	scanf("%c",&c);
	t=T;
	while(T--)
	{
	for(i=0;i<26;i++)
		a[i]=0;
	scanf("%c",&c);
	a[c-'A']++;
	while(c!='\n')
	{
		if(c<='Z'&&c>='A')
		a[c-'A']++;
		scanf("%c",&c);
	}
	a[2]=a[2]/2;
	int min=1000;
	if(a[0]<min)
		min=a[0];
	if(a[2]<min)
		min=a[2];
	if(a[7]<min)
		min=a[7];
	if(a[10]<min)
		min=a[10];
	if(a[4]<min)
		min=a[4];
	if(a[17]<min)
		min=a[17];
	if(a[15]<min)
		min=a[15];
	if(a[20]<min)
		min=a[20];	
	printf("Case #%d: %d\n",t-T,min);
	//cout<<"Case #"<<t-T<<": "<<min<<"\n";
	}
return 0;

}
