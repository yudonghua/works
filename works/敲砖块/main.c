#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

int main()
{
   char sh,a[20][31]={0};


   a[0][0]=-95;a[0][1]=-10;
   int i,j,m=10;
   for(i=0;i<20;i++)for(j=0;j<30;j+=2)
    {a[i][j]=-95;a[i][j+1]=-10;}
   for(i=6;i<19;i++)
   for(j=2;j<28;j++)
    a[i][j]=' ';
    for(i=0;i<10;i+=2){a[18][i+m]=-95;a[18][i+m+1]=-10;}
    a[17][14]=-95;a[17][15]=-15;
    for(i=0;i<20;i++)puts(a[i]);
    while(1)
    {

    }


return 0 ;
}
