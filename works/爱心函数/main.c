#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float x,y;
    for(y=1.5;y>=-1;y-=0.08)
    for(x=-1;x<0.999;x+=0.025)
    {
        if(0.90<=x*x+(y-pow(x*x,1.0/3))*(y-pow(x*x,1.0/3))&&x*x+(y-pow(x*x,1.0/3))*(y-pow(x*x,1.0/3))<=1)printf("\3");
        else printf(" ");
    }
}
