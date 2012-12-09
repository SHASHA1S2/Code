#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
	int n,m,i,j,nooflines,length_b,l;
	char a[1111];
	int b[1111];
	int T,t;
	
	scanf("%d",&T);
	t=T;
	while(T--)
{
	int x,ans,no,ch;
	scanf("%d%d",&n,&m);

//	printf("%d",x);
	j=0;l=0;
	char c;
	scanf("%c",&c);
	while(c!='\n')
	{
		if(c==' '&&l!=0)
			{b[j++]=l;l=0;}
		else if(c!=' ')
			l++;			
		scanf("%c",&c);
	}
	b[j]=l;

	int	maxb=0;
	for(i=0;i<=j;i++)
		if(b[i]>maxb)
			maxb=b[i];
	length_b=j+1;
	if(n/maxb>m) x=m;
	else x=n/maxb;
	for(ans=x;ans>0;ans--)
	{

		no=m/ans;
		ch=n/ans;
		//printf(" %d %d %d\n",ans,no,ch);
		j=0;nooflines=0;
		for(i=0;i<length_b&&nooflines<=no;i++)
		{
			j=j+b[i];
			if(j>ch)
				{nooflines++;j=0;i--;}
			else
				j++;
		}
		nooflines++;
		if(nooflines<=no)
			{printf("Case #%d: %d\n",t-T,ans);break;}
	}
	if(ans==0)
		{printf("Case #%d: %d\n",t-T,ans);}
}
	return 0;

}

