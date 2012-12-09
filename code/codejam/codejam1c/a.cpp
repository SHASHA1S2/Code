#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int cov[51][51],a[51][11];
int main()
{
	int t,i,j,p,ans,n,m;
	scanf("%d",&t);
	int T=t;
	while(t--)
	{
		for(i=0;i<51;i++)
		for(j=0;j<51;j++)
			{a[i][j]=0;cov[i][j]=0;}
		cin>>n; // no. of nodes
		for(i=1;i<=n;i++)
		{
			cin>>m;
			a[i][0]=m;
			for(j=1;j<=m;j++)
				{cin>>a[i][j];  cov[i][a[i][j]]=1;}
		}
		/*for(i=1;i<=n;i++)
		{for(j=1;j<=n;j++)
			cout<<cov[i][j]<<' ';
		cout<<endl;
		}*/
		for(int no=0;no<5;no++){
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cov[i][j]>0)
				{
					for(p=1;p<=a[j][0];p++)
						cov[i][a[j][p]]++;
				}
			}
		}
		}
		/*for(i=1;i<=n;i++)
		{for(j=1;j<=n;j++)
			cout<<cov[i][j]<<' ';
		cout<<endl;
		}*/
		ans=0;
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(cov[i][j]>1)
				ans=1;
		cout<<"Case #"<<T-t<<": ";	
		if(ans==1)
			printf("Yes\n");
		else
			printf("No\n");	

	}
}
	
