#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
void gotoxy(int x, int y) //定位到第y行的第x列
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
char sh='s',ch,a[20][31]={0};
int w[2],i,j,l,M[4][2],N[4][2],k,r,s,g=0;

int main()
{
    a[0][0]=-95;a[0][1]=-10;
   for(i=0;i<20;i++)for(j=0;j<30;j+=2)
    {a[i][j]=-95;a[i][j+1]=-10;}
   for(i=1;i<19;i++)
   for(j=2;j<28;j++)
    a[i][j]=' ';
     w[0]=7;w[1]=14;
     M[0][0]=2;M[0][1]=4;
     M[1][0]=17;M[1][1]=4;
     M[2][0]=2;M[2][1]=24;
     M[3][0]=17;M[3][1]=24;

  while(1)
{

    while (1)
         {


            Sleep(50);
            for(i=1;i<19;i++)
               for(j=2;j<28;j++)
                  a[i][j]=' ';

                if(k%10!=0)
                for(i=0;i<4;i++)
                  {

                       if(s==0)
                       {
                           if(M[i][0]!=2)
                           M[i][0]++;
                           up(M[i]);
                       }
                       if(s==1)
                       {
                           if(M[i][0]!=17)
                           M[i][0]--;
                           down(M[i]);

                       }
                       if(s==2)
                      {
                          if(M[i][1]!=4)
                          M[i][1]+=2;
                           left(M[i]);
                      }
                       if(s==3)
                       {
                           if(M[i][1]!=24)
                           M[i][1]-=2;
                           right(M[i]);
                       }
                  }
                else
                  for(i=0;i<4;i++)
                  {
                       s=rand()%4;
                       if(s==0)
                       {

                           up(M[i]);
                       }
                       if(s==1)
                       {

                           down(M[i]);

                       }
                       if(s==2)
                      {

                           left(M[i]);
                      }
                       if(s==3)
                       {

                           right(M[i]);
                       }
                  }





                if(kbhit())
                 {

                     ch=getch();
                     if(ch!='e')
                     {
                     if(ch=='w'||ch=='s')r=w[0];
                     if(ch=='a'||ch=='d')r=w[1];
                     sh=ch;
                     }if(ch!='e')switch (sh)
          {
           case 'w': case 'W':  up(w);  break;
           case 's': case 'S': down(w);  break;
           case 'a': case 'A':  left(w);  break;
           case 'd': case 'D': right(w);  break;
           case 'e': case 'E':    break;
           default: ;
          }
                 }
                     switch (sh)
          {
           case 'w': case 'W':  w[0]++; up(w);  break;
           case 's': case 'S': w[0]--; down(w);  break;
           case 'a': case 'A':   w[1]+=2; left(w);  break;
           case 'd': case 'D': w[1]-=2;right(w);  break;

           default: ;
          }

                    if(ch=='e'||ch=='E')switch (sh)
          {
          case 'w': case 'W': r--;if(r>0)
              {
              a[r][w[1]]=-95;a[r][w[1]+1]=-10;
              for(i=0;i<4;i++)
              if(r==M[i][0]&&w[1]==M[i][1]){M[i][0]=2;M[i][1]=4;}
              }  break;
          case 's': case 'S': r++;if(r<19)
              {
              a[r][w[1]]=-95;a[r][w[1]+1]=-10;
              for(i=0;i<4;i++)
              if(r==M[i][0]&&w[1]==M[i][1]){M[i][0]=2;M[i][1]=4;}
              }   break;
           case 'a': case 'A': r-=2;if(r>0)
               {
               a[w[0]][r]=-95;a[w[0]][r+1]=-10;
               for(i=0;i<4;i++)
              if(w[0]==M[i][0]&&r==M[i][1]){M[i][0]=2;M[i][1]=4;}
               }   break;
           case 'd': case 'D': r+=2;if(r<30)
               {
               a[w[0]][r]=-95;a[w[0]][r+1]=-10;
               for(i=0;i<4;i++)
              if(w[0]==M[i][0]&&r==M[i][1]){M[i][0]=2;M[i][1]=4;}
               }   break;
           default: ;
          }


system("cls");
           for(i=0;i<20;i++)puts(a[i]);

           k++;
           gotoxy(40,5);printf("按E发射子弹");
           gotoxy(40,8);printf("WASD控制方向");
           gotoxy(40,11);printf("需要命中坦克正中心");
           gotoxy(40,14);printf("塔克死亡在左上角复活");

       }
}
return 0 ;
}
up(int wo[2])
{

    if(wo[0]!=2)
    wo[0]--;
    a[wo[0]][wo[1]]=-95;a[wo[0]][wo[1]+1]=-10;
    a[wo[0]-1][wo[1]]=-95;a[wo[0]-1][wo[1]+1]=-10;
    a[wo[0]][wo[1]-2]=-95;a[wo[0]][wo[1]+1-2]=-10;
    a[wo[0]][wo[1]+2]=-95;a[wo[0]][wo[1]+1+2]=-10;
    a[wo[0]+1][wo[1]-2]=-95;a[wo[0]+1][wo[1]+1-2]=-10;
    a[wo[0]+1][wo[1]+2]=-95;a[wo[0]+1][wo[1]+1+2]=-10;


}
down(int wo[2])
{

    if(wo[0]!=17)
    wo[0]++;
    a[wo[0]][wo[1]]=-95;a[wo[0]][wo[1]+1]=-10;
    a[wo[0]+1][wo[1]]=-95;a[wo[0]+1][wo[1]+1]=-10;
    a[wo[0]][wo[1]-2]=-95;a[wo[0]][wo[1]+1-2]=-10;
    a[wo[0]][wo[1]+2]=-95;a[wo[0]][wo[1]+1+2]=-10;
    a[wo[0]-1][wo[1]-2]=-95;a[wo[0]-1][wo[1]+1-2]=-10;
    a[wo[0]-1][wo[1]+2]=-95;a[wo[0]-1][wo[1]+1+2]=-10;


}
left(int wo[2])
{

    if(wo[1]!=4)
    wo[1]-=2;
    a[wo[0]][wo[1]]=-95;a[wo[0]][wo[1]+1]=-10;
    a[wo[0]][wo[1]-2]=-95;a[wo[0]][wo[1]+1-2]=-10;
    a[wo[0]-1][wo[1]]=-95;a[wo[0]-1][wo[1]+1]=-10;
    a[wo[0]+1][wo[1]]=-95;a[wo[0]+1][wo[1]+1]=-10;
    a[wo[0]-1][wo[1]+2]=-95;a[wo[0]-1][wo[1]+1+2]=-10;
    a[wo[0]+1][wo[1]+2]=-95;a[wo[0]+1][wo[1]+1+2]=-10;


}
right(int wo[2])
{

    if(wo[1]!=24)
        wo[1]+=2;
    a[wo[0]][wo[1]]=-95;a[wo[0]][wo[1]+1]=-10;
    a[wo[0]][wo[1]+2]=-95;a[wo[0]][wo[1]+1+2]=-10;
    a[wo[0]-1][wo[1]]=-95;a[wo[0]-1][wo[1]+1]=-10;
    a[wo[0]+1][wo[1]]=-95;a[wo[0]+1][wo[1]+1]=-10;
    a[wo[0]-1][wo[1]-2]=-95;a[wo[0]-1][wo[1]+1-2]=-10;
    a[wo[0]+1][wo[1]-2]=-95;a[wo[0]+1][wo[1]+1-2]=-10;


}



