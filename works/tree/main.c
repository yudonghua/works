#include <stdio.h>
#include <stdlib.h>
typedef struct node
{ int data;
  struct node *lch,*rch;
}node;
void change(node *p){
    p->data=1;
}

int main()
{
    node *p;
    p=(node *)malloc(sizeof(node));
    change(p);
    if(p!=NULL)printf("%d",p->data);
    return 0;
}

