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
   int i,j,l,M[4],N[4],k,r,s,g=0;
   for(i=0;i<20;i++)for(j=0;j<30;j+=2)
    {a[i][j]=-95;a[i][j+1]=-10;}
   for(i=1;i<19;i++)
   for(j=2;j<28;j++)
    a[i][j]=' ';
    for(i=0;i<4;i++)
            {
                M[i]=1;
                N[i]=8+2*i;
            }
while(1)
{
      k=1;
      s=1;
      r=rand()%4;
      if(r==0)
      {
       for(i=0;i<4;i++)
            {
                M[i]=1;
                N[i]=8+2*i;
            }
      }
      if(r==1)
      {
       for(i=0;i<2;i++)
            {
                M[i]=1;
                N[i]=8+2*i;
            }
       for(i=2;i<4;i++)
            {
                M[i]=2;
                N[i]=6+2*i;
            }
      }
      if(r==2)
      {
       for(i=0;i<2;i++)
            {
                M[i]=1;
                N[i]=8+2*i;
            }
       for(i=2;i<4;i++)
            {
                M[i]=2;
                N[i]=4+2*i;
            }
      }
      if(r==3)
      {
       for(i=0;i<1;i++)
            {
                M[i]=1;
                N[i]=8+2*i;
            }
       for(i=1;i<4;i++)
            {
                M[i]=2;
                N[i]=6+2*i;
            }
      }
    while (1)
         {
         for(i=0;i<4;i++)
               if(a[M[i]][N[i]]==-95)break;
               if(i!=4)break;
             for(i=0;i<4;i++)
                 {a[M[i]][N[i]]=-95;a[M[i]][N[i]+1]=-10;}

            Sleep(80);s++;system("cls");printf("    禹华东版俄罗斯方块\n         得分%d\n",g);for(i=0;i<20;i++)
          puts(a[i]);printf("游戏说明：AD控制左右\n    W变形S加速\n",g);
            for(i=0;i<4;i++)
       {a[M[i]][N[i]]=32;a[M[i]][N[i]+1]=32;}



                if(kbhit())
                 {
                     sh=getch();switch (sh)
          {
           case 'w': case 'W':  for(i=1;i<4;i++)
           {
               if(r==1&&i==1){for(j=2;j<4;j++)M[j]-=2*k;}
               if(r==2)break;
               if(r==3&&i==1){for(j=1;j<4;j++)M[j]-=2*k;}
                  M[i]+=k*i;N[i]-=k*2*i;

           }k=-k; break;
           case 's': case 'S':  for(i=0;i<4;i++)M[i]++; break;
           case 'a': case 'A':  for(i=0;i<4;i++)N[i]-=2; break;
           case 'd': case 'D':  for(i=0;i<4;i++)N[i]+=2; break;
           default: ;
          }
                 }
                 if(s%5==0)for(i=0;i<4;i++)M[i]++;

        }
   for(i=0;i<4;i++)M[i]--;
for(i=0;i<4;i++)
       {a[M[i]][N[i]]=-95;a[M[i]][N[i]+1]=-10;}



        for(i=18;i>0;i--)
        {   k=0;
            for(j=2;j<28;j+=2)
             if(a[i][j]==-95)k++;
             if(k==13)
           {for(l=i;l>1;l--)for(j=2;j<28;j++)
        a[l][j]=a[l-1][j];i++;g++;
           }

        }



}
return 0 ;
}
