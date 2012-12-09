#include<iostream>
#include<stdio.h>
#include<set>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int n;
int arr[1000];
vector< vector<int> > mat(1000);
bool visited[1000];
vector<int> S1;
vector<int> S2;

void dfs(int n)
{
  if(visited[n])
    return;
  visited[n]=true;
  S1.push_back(n);
  S2.push_back(arr[n]);
  for(int i=0;i<mat[n].size();i++)
    dfs(mat[n][i]);
}

void process(int n)
{
  S1.clear();
  S2.clear();
  dfs(n);
  sort(S1.begin(),S1.end());
  sort(S2.begin(),S2.end());
  for(int i=0;i<S1.size();i++)
    arr[S1[i]]=S2[i];
}

int main()
{
  char tmp[1000];
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  for(int i=0;i<n;i++)
  {
    scanf("%s",tmp);
//     printf("%s\n",tmp);
    for(int j=0;j<n;j++)
      if(tmp[j]=='y')
	mat[i].push_back(j);
  }
//   for(int i=0;i<n;i++)
//   {
//     printf("%d > ",i);
//     for(int j=0;j<mat[i].size();j++)
//       printf("%d ",mat[i][j]);
//     printf("\n");
//   }
  memset(visited,false,sizeof(visited));
  for(int i=0;i<n;i++)
  {
    if(!visited[i])
      process(i);
    else
      continue;
  }
  for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
  printf("\n");
}
