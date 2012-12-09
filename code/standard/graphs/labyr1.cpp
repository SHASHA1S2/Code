#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int visited[1001][1001];
char A[1001][1001];
int M,N;
typedef struct P
{
	int max;
	int max_indi;
	int max_indj;
}P;

P ans;

void dfs(int i, int j)
{
	int v=visited[i][j];
	if(v>ans.max)
		{ans.max=v;ans.max_indi=i;ans.max_indj=j;}
	if(A[i][j+1]=='.' && visited[i][j+1]==0 && j+1<=M)		{visited[i][j+1]=v+1;dfs(i,j+1);}
	if(A[i][j-1]=='.' && visited[i][j-1]==0 && j-1>=1)		{visited[i][j-1]=v+1;dfs(i,j-1);}
	if(A[i+1][j]=='.' && visited[i+1][j]==0 && i+1<=N)		{visited[i+1][j]=v+1;dfs(i+1,j);}
	if(A[i-1][j]=='.' && visited[i-1][j]==0 && i-1>=1)		{visited[i-1][j]=v+1;dfs(i-1,j);}		
}

int main()
{
	int T,i,j;
	char c;
	cin>>T;
	while(T--)
	{
		memset(visited,0,sizeof(visited));
		scanf("%d%d",&M,&N);
		int dfsi,dfsj;
		for(i=1;i<=N;i++){
			scanf("%c",&c);
			for(j=1;j<=M;j++)
			{
				scanf("%c",&A[i][j]);
				if(A[i][j]=='.')
					{dfsi=i;dfsj=j;}
			}
		}
		ans.max=0;
		visited[dfsi][dfsj]=1;
		dfs(dfsi,dfsj);
		memset(visited,0,sizeof(visited));
		ans.max=0;
		dfsi=ans.max_indi;dfsj=ans.max_indj;
		visited[dfsi][dfsj]=1;
		dfs(ans.max_indi,ans.max_indj);
		printf("Maximum rope length is %d.\n",ans.max-1);
	}
	return 0;
}
