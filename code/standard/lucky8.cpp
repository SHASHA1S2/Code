#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
int  a[22],b[22],c[22],d[22];

int  f(int  n4,int  n7,int  i)
{
	int  k=(n7+i-n4)/2;
	if(k*(i-k)>=0) return (n4+k)*(n7+i-k);
	k++;
	if(k*(i-k)<=0) return (n4+k)*(n7+i-k); 
	return max((n4+i)*n7,n4*(n7+i)); 
}
int solve(LL l,LL r)
{
	int  i=0;
	int templ=l,tempr=r;
	while(tempr!=0)
	{
		c[i]=templ%10;d[i++]=tempr%10;
		templ/=10;tempr/=10;
	}
	int  len=i;
	for(i=0;i<len;i++){
		a[i]=c[len-(1+i)];
		b[i]=d[len-(1+i)];
		//cout<<a[i]<<' '<<b[i]<<endl;
	}
	i=0;
	int  no4=0,no7=0;
	while(a[i]==b[i]&& i<len){
		if(a[i]==4)	no4++;
		if(a[i]==7) no7++;
		i++;
		}
	int  diffindex=i;
	if(diffindex==len)
		return no4*no7;		
	int  tempno4=no4,tempno7=no7;
	int ans,maxans=0;
	for(int  k=a[diffindex]+1;k<b[diffindex];k++)
	{
		if(k==4)	no4++;
		if(k==7) 	no7++;
//		for(LL  j=diffindex+1;j<len;j++) // j is for the index , k for the digit
//			if(no4<no7) no4++;
//			else	no7++;
		ans=f(no4,no7,len-(diffindex+1));
		if(ans>maxans)
			maxans=ans;
		no4=tempno4;
		no7=tempno7;
	}
	for(int  j=diffindex;j<len;j++) 	// keeping 0-j same as l
	{
		no4=0;no7=0;
		for(i=0;i<=j;i++)
		{
			if(a[i]==4)	no4++;
			if(a[i]==7)	no7++;
		}
		if(j==len-1) {
			ans=no4*no7;
			if(ans>maxans)
				maxans=ans;
			no4=tempno4;
			no7=tempno7;
			continue;
		}
		for(int  k=a[j+1]+1;k<10;k++)  // j+1 th digit 
		{
				if(k==4) 	no4++;
				if(k==7)	no7++;
//				for(i=j+2;i<len;i++)
//					if(no4<no7)	no4++;
//					else no7++;
				
				ans=f(no4,no7,len-(j+2));
				if(ans>maxans)
					maxans=ans;
				no4=tempno4;
				no7=tempno7;			
		}
	}
	
	for(int j=diffindex;j<len;j++) 	// keeping 0-j same as r
	{
		no4=0;no7=0;
		for(i=0;i<=j;i++)
		{
			if(b[i]==4)	no4++;
			if(b[i]==7)	no7++;
		}
		if(j==len-1) {
			ans=no4*no7;
			if(ans>maxans)
				maxans=ans;
			no4=tempno4;
			no7=tempno7;
			continue;
		}
		
		
		for(int  k=b[j+1]-1;k>=0;k--)  // j+1 th digit 
		{
				if(k==4) 	no4++;
				if(k==7)	no7++;
//				for(i=j+2;i<len;i++)
//					if(no4<no7)	no4++;
//					else no7++;
				ans=f(no4,no7,len-(j+2));
				if(ans>maxans)
					maxans=ans;
				no4=tempno4;
				no7=tempno7;			
		}
		
	}
	return maxans;
}

int  main()
{
	int  t;
	cin>>t;
	LL l,r;
	while(t--)
	{
		cin>>l>>r;
		if(l>r)	cout<<0<<endl;
		else	cout<<solve(l,r)<<endl;
	}

return 0;
}
