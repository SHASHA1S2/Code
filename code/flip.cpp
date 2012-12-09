#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Tree{
  bool flip;
  int total;
  int heads;
};

typedef struct Tree Tree;

Tree tree[1<<18];

Tree nullTree;

Tree merge(Tree a, Tree b)
{
  Tree ans;
  ans.total=a.total+b.total;
  if(a.flip==b.flip)
  {
    ans.heads=a.heads+b.heads;
    ans.flip=a.flip;
  }
  else
  {
    b.heads=b.total-b.heads;
    ans.heads=a.heads+b.heads;
    ans.flip=b.flip=a.flip;
  }
  return ans;
}

void init(int n_val)
{
  int i;
  for(i=(1<<n_val)-1;i>=(1<<(n_val-1));i--)
  {
    tree[i].flip=0;
    tree[i].heads=0;
    tree[i].total=1;
  }
  for(i=(1<<(n_val-1))-1;i>0;i--)
    tree[i]=merge(tree[2*i],tree[2*i+1]);
}


void update(int root, int LL, int RR, int a, int b) //[l,h) [a,b)
{
  if(root>0)
    printf("%d %d %d %d %d in update\n", root,LL,RR,a,b);
  if(a>RR || b<LL)
    return;
  if(a<=LL && b>=RR)
  {
    tree[root].flip^=1;
    tree[root].heads=tree[root].total-tree[root].heads;
    return;
  }
  int l=root*2, h=l+1, mid=(LL+RR)/2;
  if(a<mid)
    update(l,LL,mid,a,b);
  if(b>mid)
    update(h,mid,RR,a,b);
//   int mid=(LL+RR)/2;
//   update(2*root,LL,mid,a,b);
//   update(2*root+1,mid,RR,a,b);
  bool flip=tree[root].flip;
  tree[root]=merge(tree[2*root],tree[2*root+1]);
  if(tree[root].flip!=flip)
  {
    tree[root].flip=flip;
    tree[root].heads=tree[root].total-tree[root].heads;
  }
}

Tree query(int root, int LL, int RR, int a, int b)
{
  printf("%d %d %d %d %d in query\n", root,LL,RR,a,b);
  if(a>RR || b<LL)
    return nullTree;
  if(a<=LL && b>=RR)
    return tree[root];
  int l=root*2, h=l+1, mid=(LL+RR)/2;
  Tree x=nullTree, y=nullTree;
  if(a<mid)
    x=query(l,LL,mid,a,b);
  if(b>mid)
    y=query(h,mid,RR,a,b);
//   int mid=(LL+RR)/2;
//   Tree x=query(2*root,LL,mid,a,b);
//   Tree y=query(2*root+1,mid,RR,a,b);
//   bool flip=tree[root].flip;
//   Tree ans=merge(x,y);
//   if(ans.flip!=flip)
//   {
//     ans.flip=flip;
//     ans.heads=ans.total-ans.heads;
//   }
//   return ans;
  return merge(x,y);
}

void display(int n_val)
{
  int i;
  for(i=0;i<(1<<n_val)-1;i++)
    printf("%d ",tree[i].heads);
  printf("\n");
}

int main()
{
  nullTree.heads=nullTree.total=nullTree.flip=0;
  int n,q,i;
  int root=1;
  scanf("%d %d",&n,&q);
  int n_val=20;
  for(i=1;i<21;i++)
  {
    if((n+1)>(1<<(i-1)) && (n+1)<=(1<<i))
    {
      n_val=i;
      break;
    }
  }
//   printf("%d begining init\n",n_val);
  init(n_val);
//   printf("initialised\n");
//   init();
//   display(n_val);
  for(i=0;i<q;i++)
  {
    int ch,a,b;
    scanf("%d %d %d",&ch,&a,&b);
    a++;b++;
    if(ch==0)
      update(root,1,1<<3,a,b);
    else
    {
      Tree ans=query(root,1,1<<3,a,b);
      if(ans.flip)
	printf("%d\n",ans.total-ans.heads);
      else
	printf("%d\n",ans.heads);
    }
     display(n_val);
  }
}