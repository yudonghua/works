#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
void gotoxy(int x, int y)
{
int xx=0x0b;
HANDLE hOutput;
COORD loc;
loc.X = x;
loc.Y=y;
hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hOutput, loc);
return;
}
int main()
{
    srand(time(0));
    int i,j,k=1,m=3,n=6,x,y,M[20],N[20];
    char sh,a[20][41]={0};
    v : m=3;n=6;M[0]=3;N[0]=6;k=1;
    for(j=0;j<20;j++)for(i=0;i<40;i+=2)
    {a[j][i]=-95;a[j][i+1]=-10;}
    for(j=1;j<19;j++)for(i=2;i<38;i+=2)
    {a[j][i]=32;a[j][i+1]=32;}
    a[m][n]=-95;a[m][n+1]=-10;
    x=rand()%17+1;y=rand()%17*2+2; a[x][y]=-95;a[x][y+1]=-10;
    gotoxy(0,0);for(i=0;i<20;i++)puts(a[i]);
    gotoxy(10,10);
    printf("按任意键开始");
    sh=getch();
while (1)
         {
            Sleep(100-5*k);gotoxy(0,0);
            M[k]=m;N[k]=n;
            if(x==m&&y==n)
            {x=rand()%17+1;y=rand()%17*2+2;a[x][y]=-95;a[x][y+1]=-10;k++; M[k]=m;N[k]=n;}
            for(i=0;i<k;i++)
            {
                M[i]=M[i+1];N[i]=N[i+1];
            }
                if(kbhit())
                 {sh=getch();}switch (sh)
          {
           case 'w': case 'W':  m--; break;
           case 's': case 'S':  m++; break;
           case 'a': case 'A':  n-=2; break;
           case 'd': case 'D':  n+=2; break;
           default: ;
          }
       a[M[0]][N[0]]=32;a[M[0]][N[0]+1]=32;
          for(i=1;i<k;i++)
               {
                   a[M[k]][N[k]]=-95;a[M[k]][N[k]+1]=-10;
               }
               if(a[m][n]==-95&&m!=x&&n!=y)break;
       a[m][n]=-95;a[m][n+1]=-10;
          for(i=0;i<20;i++)
          puts(a[i]);
          printf("    得分%d",k);
         }
         while(1){for(i=0;i<20;i++)puts(a[i]);
          printf("    得分%d",k);goto v;}
return 0;
}


