#include<cstdio>
//#include<algorithm>
using namespace std;
int c[10000],d[10000];
int b[10000];
int count=0;
void merge_sort(int start,int end)
{
	int i,j;
	int length=end-start+1;
	if (length<=1)
		return;
	int mid=length/2;
	mid+=start;
	merge_sort(start,mid-1);
	merge_sort(mid,end);	
	
	int k=start;
	for(i=start,j=mid;i<mid&&j<=end;)
	{
		if(b[count++]==1)
		{
			d[(k)]=c[i++];
		}
		else
			d[k]=c[j++];
		k++;	
	}
	for(;k<=end&&i<mid;)
		d[k++]=c[i++];
	for(;k<=end&&j<=end;)
		d[k++]=c[j++];

	for(i=start;i<=end;i++)	
		c[i]=d[i];
}

int main()
{
	int i;
	int N;
	scanf("%d",&N);
	char ch;
	scanf("%c",&ch);
	scanf("%c",&ch);
	int b_len=0;
	while(ch!='\n')
	{	
		if(ch-'0'==1||ch-'0'==2) 
		b[b_len++]=ch-'0';
		scanf("%c",&ch);		
	}
	for(i=1;i<=N;i++)
		c[i]=i;
	merge_sort(1,N);
	for(i=1;i<=N;i++)
		printf("%d ",c[i]);

}
