#include <stdio.h>
#include <stdlib.h>
double op();
int main()
{
    double a[100];
    char b[100];
    double sum=0;
    int i=0,j=-1,k;
    while(1){
    do
    {
        j++;
        scanf("%lf",&a[j]);
        v:scanf("%c",&b[j]);

    }
    while(b[j]!='('&&b[j]!='=');
    for(i=0;i<j;i++)printf("%f %c ",a[i],b[i]);
    if(b[j]=='('){a[j]=op();goto v;}
    if(b[j]=='=')
    for(i=0;i<j;i++)
        switch(b[i])
        {
            case '*' :a[i]=a[i]*a[i+1];for(k=i+1;k<j;k++){a[k]=a[k+1];b[k-1]=b[k];}i--;j--;
                break;
            case '/' :a[i]=a[i]/a[i+1];for(k=i+1;k<j;k++){a[k]=a[k+1];b[k-1]=b[k];}i--;j--;
                break;
            case '+' :;
                break;
            case '-' :a[i+1]=-a[i+1];
            default : ;
        }

    for(i=0;i<j+1;i++)sum+=a[i];
    printf("%f\n",sum);
}
}
double op(){
    double a[100];
    char b[100];
    double sum=0;
    int i=0,j=-1,k;
    do
    {
        if(b[j]=='('){a[j]=op();}
        j++;
        scanf("%lf",&a[j]);
        scanf("%c",&b[j]);
    }
    while(b[j]!=')');
    for(i=0;i<j;i++)
        switch(b[i])
        {
            case '*' :a[i]=a[i]*a[i+1];for(k=i+1;k<j;k++){a[k]=a[k+1];b[k-1]=b[k];}i--;j--;
                break;
            case '/' :a[i]=a[i]/a[i+1];for(k=i+1;k<j;k++){a[k]=a[k+1];b[k-1]=b[k];}i--;j--;
                break;
            case '+' :;
                break;
            case '-' :a[i+1]=-a[i+1];
            default : ;
        }

    for(i=0;i<j+1;i++)sum+=a[i];
    return sum;
}

