#include<cstdio>
#include<iostream>

using namespace std;

int maxheap[1000];
int heappointer=1;

void insert(int p)
{
	int temp,i;
	maxheap[heappointer++]=p;
	for(i=heappointer-1;i>=2;)
	{
		if(maxheap[i]>maxheap[i/2])
			{temp=maxheap[i];maxheap[i]=maxheap[i/2];maxheap[i/2]=temp;}
		else
			break;
		i=i/2;
	}
}

void del()
{
	int temp,i;
	maxheap[1]=maxheap[heappointer-1];
	heappointer--;
	for(i=1;i<=heappointer/2;)
	{
		if(maxheap[i]>=maxheap[2*i] && maxheap[i]>=maxheap[2*i+1])
			break;
		else if(maxheap[2*i]>=maxheap[2*i+1])
			{temp=maxheap[i];maxheap[i]=maxheap[2*i];maxheap[2*i]=temp;i=2*i;}
		else 
			{temp=maxheap[i];maxheap[i]=maxheap[2*i+1];maxheap[2*i+1]=temp;i=2*i+1;}
	}
	
}
int main()
{
	int i,n,a;	
	for(i=0;i<10;i++)
		{scanf("%d%d",&a,&n);if(a==1) insert(n);else del();printf("%d",maxheap[1]);}
	
	return 0;
	


}
