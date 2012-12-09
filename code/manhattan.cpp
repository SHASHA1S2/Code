#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

typedef struct point{
int x;
int y;
int count;
}point;

int maxn=20000000,N,i;
point a[200009];
int b[200009];

bool compare(point a,point b)
{
	return a.x<b.x;
}

int mod(int x)
{
	if(x<0) return -x;
	return x;
}

int main()
{
	cin>>N;
	int j;
	for(i=0;i<N;i++)		{scanf("%d%d",&a[i].x,&a[i].y);   a[i].count=i;}
	sort(a,a+N,compare);
	//for(i=0; i<N; i++)      	{cout<<a[i].x<<a[i].y<<a[i].count;}
	for(i=0;i<N;i++)
	{
		int min=maxn;
		for(j=1;;j++)
		{
			if(i+j>=N) break;
			int c=mod(a[i+j].x-a[i].x)+mod(a[i+j].y-a[i].y);
			if(min>c)  min=c;			
			if(a[i+j].x>=(a[i].x+c)) break;

		}
		for(j=-1;;j--)
		{
			if(i+j<0) break;
			int c=mod(a[i+j].x-a[i].x)+mod(a[i+j].y-a[i].y);
			if(min>c)  min=c;			
			if(a[i+j].x>=(a[i].x+c)) break;

		}
		b[a[i].count]=min;
	}
	for(i=0;i<N;i++) 	printf("%d\n",b[i]);
	return 0;
}
	
