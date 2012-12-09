// code for project file dependancys
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

vector<int> a[105];
int dependancy[105];
int visited[105];
int v;

int main()
{
	int N,M,va,vb,i,k,j;
	cin>>N>>M;
	for(i=0;i<M;i++)
	{
		scanf("%d%d",&va,&k);
		dependancy[va]=k;
		while(k--)
		{
			scanf("%d",&vb);
			a[vb].push_back(va);
		}
	}
	for(i=1;i<=N;i++)	// jsut to run n times
	{
		for(j=1;j<=N;j++)
			if(dependancy[j]==0 & visited[j]==0)
				break;
		printf("%d ",j);
		visited[j]=1;
		for(k=0;k<a[j].size();k++)
		{
			vb=a[j][k];
			dependancy[vb]--;
		}
	}
	cout<<endl;
	return 0;
}
