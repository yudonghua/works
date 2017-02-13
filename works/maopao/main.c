#include <stdio.h>
#include <stdlib.h>
void maopao(int &a){
    a=4;
    printf("%d",a);
}

int main()
{
    int a;
    scanf("%d",&a);
    maopao(a);
    printf("%d",a);
    return 0;
}

