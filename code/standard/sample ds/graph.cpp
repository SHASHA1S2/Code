#include<cstdio>
#include<iostream>

using namespace std;
int A[200][200],V[200][200],M,N,val;
int dfs(int i,int j)
{
	int min=A[i][j],mininit=0,dfsi=0,dfsj=0;
	if(i>1 && (A[i-1][j]<min))
		{min=A[i-1][j];dfsi=i-1;dfsj=j;}
	if(j>1 && (A[i][j-1]<min))
		{min=A[i][j-1];dfsi=i;dfsj=j-1;}
	if(j<M && ( A[i][j+1]<min))
		{min=A[i][j+1];dfsi=i;dfsj=j+1;}
	if(i<N && ( A[i+1][j]<min))
		{min=A[i+1][j];dfsi=i+1;dfsj=j;}
	
	if(dfsj==0 && dfsi==0) {V[i][j]=val;val++;return V[i][j];}
	if(V[dfsi][dfsj]!=0) {V[i][j]=V[dfsi][dfsj];return V[i][j];}
	int ret=dfs(dfsi,dfsj);
	V[i][j]=ret;
	return V[i][j];
}


int main()
{
	long long T,i,j;
	cin>>T;
	int t=T;
	while(T--)
	{
		cout<<"Case #"<<t-T<<":"<<endl;
		cin>>N>>M;
		for(i=1;i<=N;i++)
		for(j=1;j<=M;j++)
			{scanf("%d",&A[i][j]);V[i][j]=0;}
		val=1;
		
		for(i=1;i<=N;i++)
		for(j=1;j<=M;j++)
			if(V[i][j]==0)
			{
				
				dfs(i,j) ;
					
			}
		
		for(i=1;i<=N;i++){
		for(j=1;j<=M;j++)
			printf("%c ",'a'+(V[i][j]-1));;
		cout<<endl;	
		}
	}
	return 0;
}
