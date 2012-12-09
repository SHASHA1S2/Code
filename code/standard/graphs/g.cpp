#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

typedef struct node
{
	int col;
	int weight;
	int index;
}node;

int visited[1000];
int E[1000][1000];
node N[1000];
int n;
void init()
{
	int i;
	for(i=0;i<1000;i++)
		E[i][0]=0;

}

int bfs(int i)
{
	queue<int> Q;
	Q.push(i);
	int ans=0;
	for(int j=0;j<1000;j++)
		visited[j]=0;
	while(!Q.empty())
	{
		int index=Q.front();
		Q.pop();
		ans+=N[index].weight;
		visited[index]=1;
		for(int j=1;j<=E[index][0];j++){
			if(visited[E[index][j]]==0 && N[E[index][j]].col==N[index].col)
				Q.push(E[index][j]);
			visited[E[index][j]]=1;
		}
		if(Q.empty()){
			for(int j=0;j<n;j++)
				if(visited[j]==0){
					Q.push(j);
					break;
				}
			}
	}
	return ans;
}


int main()
{
	int T,m,n1,n2,i,ret;
	char c;
	cin>>T;
	while(T--)
	{
		init();
		scanf("%d%d",&n,&m);
		int weightsum=0;
		for(i=0;i<n;i++)
		{
			scanf("%c",&c);
			scanf("%c%d",&c,&N[i].weight);
			N[i].index=i;
			if(c=='A') N[i].col=0;
			else N[i].col=1;
			weightsum+=N[i].weight;
		}
		while(m--)
		{
			scanf("%d%d",&n1,&n2);
			n1--;n2--;
			E[n1][E[n1][0]++] = n2;
			E[n2][E[n2][0]++] = n1;
		}
		int max=0;
		for(i=0;i<n;i++){
			ret=bfs(i);
//			cout<<ret<<' ';
//			cout<<ret;
			if(ret>max)
				max=ret;
		}
		cout<<weightsum-max<<endl;
				
	}
	return 0;
}
