#include<stdio.h>
int main()
{
    int *a,n,l=0,i,m;
    printf("      求1到n的全排列\n输入一个数:");
    scanf("%d",&n);m=n;
    a=(int *)malloc(sizeof(int)*m);
    q(m,l,n,a);
    for(i=0;i<m;i++)printf("%d ",a[i]);
}
q(int m,int l,int n,int *a)
{
    int i,j;
    for(i=0;i<n+l;i++)
    {
        a[l]=1+i;
        if(l==m)
    {
        if(p(m,a))
        {
            for(j=0;j<m;j++)printf("%d ",a[j]);
            printf("\n");
        }
        return 0;
    }
        q(m,l+1,n-1,a);
    }
}
p(int m,int *a)
{
    int i;
    int *b;
    b=(int *)malloc(sizeof(int)*m);
    for(i=0;i<m;i++)
    b[i]=0;
    for(i=0;i<m;i++)
    b[a[i]-1]++;
    for(i=0;i<m;i++)
    if(b[i]>1)return 0;
    return 1;
}
