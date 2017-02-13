#include <iostream>
#define NUM 8
using namespace std;
typedef struct node
{ int data;
  struct node *lch,*rch;
}node;
void left(node* &p,int test);
void mid (node *root)
{
    if (root!=NULL)
    {
        mid(root->lch);
        cout<<root->data<<" ";
        mid(root->rch);
    }
}

void right(node* &p,int test)
{
    if(p==NULL){
        p=new node;
        p->data=test;
        p->lch=NULL;
        p->rch=NULL;
    }
    else{
    if(test<=p->data){
                left(p->lch,test);
            }
            else{
                right(p->rch,test);
            }
    }

}

void left(node* &p,int test)
{
    if(p==NULL){
        p=new node;
        p->data=test;
        p->lch=NULL;
        p->rch=NULL;
    }

    else{
    if(test<=p->data){
                left(p->lch,test);
            }
            else{
                right(p->rch,test);
            }
    }
}

int main()
{
    node *p;
    int i,test[NUM];
    p=NULL;
    for(i=0;i<NUM;i++){
        cin>>test[i];
    }
    for(i=0;i<NUM;i++){
        if(p==NULL){
            p=new node;
            p->data=test[i];
            p->lch=NULL;
            p->rch=NULL;
        }
        else{
            if(test[i]<=p->data){
                left(p->lch,test[i]);
            }
            else{
                right(p->rch,test[i]);
            }
        }
    }
    mid(p);
    return 0;
}


