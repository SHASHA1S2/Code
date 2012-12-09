#include<cstdio>
#include<math.h>
//#include<string.h>
int a[2010][2010];
int deg[2010];
int alpha;
using namespace std;
int main()
{
	int i,b,c,maxdegree,j,index,x;
	int T,N;
	scanf("%d",&T);
	while(T--)
	{
		alpha=0;
		for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			a[i][j]=0;
		scanf("%d",&N);
		for(i=0;i<N;i++)
			deg[i]=0;
		for(i=1;i<N;i++)
		{		scanf("%d%d",&b,&c);a[b][c]=1;a[c][b]=1;deg[c]++;deg[b]++;}
		maxdegree=0;index=0;		
		for(i=0;i<=N-1;i++)
		{
		if(deg[i]>maxdegree)
			{maxdegree=deg[i];index=i;}
		}	
	
		
		for(i=0;i<N;i++)
		{
			if(a[index][i]==1)
			{		if(deg[i]==2)
				{
					for(j=0;j<N;j++)
					{
						if((a[i][j]==1)&&(j!=index))
							if(deg[j]==1)
								alpha++;				
					}		
				}
			}
		}
		if(alpha==3)
			maxdegree++;		
		printf("%d\n",maxdegree);	

	}
return 0;
}
