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
	cin>>N>>M;
	for(i=0;i<M;i++)
	{
		scanf("%d%d",&va,&vb);
		a[va].push_back(vb);
		a[vb].push_back(va);
	}
	visited[1]=1;
	dfs(1);
	if(!tree)
		{cout<<"NO"<<endl;return 0;}
	for(i=1;i<=N;i++){
//		cout<<visited[i];
		if(visited[i]==0)
			{break;}}
	if(i==N+1) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
		
	return 0;

}
