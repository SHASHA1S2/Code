#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdlib>

using namespace std;

int W , H , N , Q ;
const int maxn = 100005;

struct point {
	int x,y;
};

point a[maxn],b[maxn],c[maxn];

bool compare1(point a , point b){
	if(a.x == b.x ) return a.y < b.y;
	return a.x < b.x;
}

bool compare2(point a , point b){
	if(a.y == b.y)return a.x < b.x;
	return a.y < b.y;
}

int arr1[maxn] , arr2[maxn];

int main(){
	cin>>W >> H >> N >>Q;
	for(int i=0;i<N;i++){
		int t1,t2;
		cin>>t1>>t2;
		a[i].x = t1;
		a[i].y = t2;
	}
	for(int i=0;i<N;i++){
		b[i]=a[i]; c[i] = a[i];	
	}
	
	sort(b,b+N,compare1);
	sort(c,c+N,compare2);
	
	for(int i=0;i<N;i++){
		arr1[i] = b[i].x;
		arr2[i] = c[i].y;
	}
	cout<<endl<<endl;
	for(int i=0;i<N;i++){
		cout<<arr2[i]<<endl;	
	}	
	
	cout<<"this"<<endl;	
	for(int i=0;i<Q;i++){
		int t1,t2;
		cin>>t1>>t2;
		int temp1 = min(arr1[upper_bound(arr1,arr1+N,t1)-arr1] , arr1[lower_bound(arr1,arr1+N,t1)-arr1]);
		int temp2 = min(arr2[upper_bound(arr2,arr2+N,t2)-arr2] , arr2[lower_bound(arr2,arr2+N,t2)-arr2]);
		
		cout<<temp1<<" "<<temp2<<endl;		
		cout<<2 * min(temp1 , temp2)<<endl;	
	}
	return 0;
}
