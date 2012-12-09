#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;

typedef struct node
{
	int value;
	struct node *parent,*left,*right;
}node;

typedef struct tree
{
	node* root;
}tree;

queue<node*> Q;
void bfs(node* p)
{
	Q.push(p);
	node* z;
	while(!Q.empty())
	{
		z=Q.front();
		Q.pop();
		if(z->left!=NULL) {Q.push(z->left);}
		if(z->right!=NULL) Q.push(z->right);
		cout<<z->value<<' ';
	}

}
int main()
{
	int pre[100],leaf[100],i;
	for(i=0;i<5;i++)
		cin>>pre[i];
	for(i=0;i<5;i++)
		cin>>leaf[i]; // 1 if its a leaf

	tree T;
	node* p,*q;
	p=(node*)malloc(sizeof(node));
	T.root=p;
	p->left=NULL;p->right=NULL;p->parent=NULL;
	q=p;
	p->value=pre[0];p->left=(node*)malloc(sizeof(node));p=p->left;


	for(i=1;i<5;i++){
		p->parent=q;p->left=NULL;p->right=NULL;
		p->value=pre[i];
		q=p;
		if(leaf[i]==1){
			while(p!=T.root && p==p->parent->right  )
				p=p->parent;
			if(p==T.root) break;
			q=p->parent;
			q->right=(node*)malloc(sizeof(node));
			p=q->right;
		}
			
		else{
			q=p;
			p->left=(node*)malloc(sizeof(node));
			p=p->left;
			
		}
	}
//	cout<<i;
	bfs(T.root);
}
