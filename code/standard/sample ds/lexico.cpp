//3
//3 1 2
//nny
//nnn
//ynn
//output:
//2 1 3
//N size of permutation P.First line of input is N.Second line is the permutation P.A Permutation X is said to be lexicographically smaller than Y if for all digits till i X[i]=Y[i] and for i+1 X[i]<=Y[i]so you can exchange the integers in the given permutation P if character j of line i+2 is 'y' then i th and j th integer in P can be exchanged .
//Output:Lexicographically smallest premutation of the given P using rule


#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int visited[100];
int arr[100][100];
int A[100];
int N;
vector<int> S[100];
vector<int> s1;
vector<int> s2;
void dfs(int i)
{
	if(visited[i]==1)
		return;
	else
		{visited[i]=1;s1.push_back(i);s2.push_back(A[i]);}		
	int j;
	for(j=1;j<=N;j++){
		if(visited[j]==0 && arr[i][j]==1){
			visited[j]=1;dfs(j);s1.push_back(j);s2.push_back(A[j]);		
		}
	}
}

int main()
{
	int t,i,j;
	cin>>N;
	for(i=1;i<=N;i++)
		cin>>A[i];
	char c;
	for(i=1;i<=N;i++){
//		cin>>c;
		for(j=1;j<=N;j++){
				cin>>c;
				if(c=='y')
					arr[i][j]=1;
				else
					arr[i][j]=0;
		}
	}
//	for(i=1;i<=N;i++)
//	for(j=1;j<=N;j++)
//		cout<<arr[i][j];
//	cout<<endl;
	int count=1;
	for(i=1;i<=N;i++)
		if(visited[i]==0){
				s1.clear();
				s2.clear();
				dfs(i);
				sort(s1.begin(),s1.end());
				sort(s2.begin(),s2.end());
				for(i=0;i<s1.size();i++)
					A[s1[i]]=s2[i];				
		}
	for(i=1;i<=N;i++)
		cout<<A[i];
	
		
	return 0;
}
