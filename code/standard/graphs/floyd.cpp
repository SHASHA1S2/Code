#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int a[100];
vector <int> E[100];
int N;
int visited[100];


int main()
{
	int M,v1,v2,i,j,temp;
	cin>>N>>M;
	for(i=1;i<=N;i++)
		cin>>a[i];
	for(j=1;j<=M;j++)
		{
			cin>>v1>>v2;
			E[v1].push_back(v2);
			E[v2].push_back(v1);
		}
	
	for(k=1;k<=N;k++)
	for(i=1;i<=N;i++)
	for(j=1;j<=N;j++)
	{
		
	}


}	
