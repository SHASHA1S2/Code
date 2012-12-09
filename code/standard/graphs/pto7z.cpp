// code for finding the maximum length of a path in an undirected graph
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

vector<int> a[10005];
int visited[10005];
int v;
bool tree=true;
void dfs(int i)
{
	for(int j=0;j<a[i].size();j++)
	{
		v=a[i][j];
		if(visited[v]==0) 
			{visited[v]=visited[i]+1;dfs(v);}
		else if( visited[v]==visited[i]-1)
			{}
		else
			tree=false;
	}

}


int main()
{
	int N,M,va,vb,i;
	cin>>N;
	for(i=0;i<N-1;i++)
	{
		scanf("%d%d",&va,&vb);
		a[va].push_back(vb);
		a[vb].push_back(va);
	}
	dfs(1);
	int max=1,max_ind=1;
	for(i=1;i<=N;i++)	
	{
		if(visited[i]>max)
			{max=visited[i];max_ind=i;}
	}	
	for(i=1;i<=N;i++)
		visited[i]=0;
	visited[max_ind]=1;
	dfs(max_ind);
	max=1;
	for(i=1;i<=N;i++)
		if(visited[i]>max)
			max=visited[i];
	printf("%d\n",max-1);
	return 0;

}
