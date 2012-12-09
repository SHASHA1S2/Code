#include<cstdio>
#include<iostream>
#include<vector> 

using namespace std;

vector<int> A;
void quick_sort(int start,int end)  //[start, end)
{
	int i;
	if(start>=end-1)
		return;
	int pivot=A[start];
	vector<int> less,greater;
	for(i=start+1;i<end;i++){
		if(A[i]<A[start])
			less.push_back(A[i]);
		else
			greater.push_back(A[i]);
	}
	int j=start;
	for(i=0;i<less.size();i++)
		A[j++]=less[i];
	A[j++]=pivot;
	for(i=0;i<greater.size();i++)	
		A[j++]=greater[i];
	quick_sort(start,start+less.size());
	quick_sort(start+less.size()+1,end);

}

int  main()
{
	int i;

	A.push_back(2);
	A.push_back(4);
	A.push_back(2);
	A.push_back(1);
	quick_sort(0,4);
	for(i=0;i<4;i++)
		cout<<A[i];
	return 0;
}
