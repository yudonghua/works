#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
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
int main()
{
    srand(time(0));
    int i,j,z,l=0,k=0,m,n=8;
    char p[]="●";
    char sh,a[15][41]={0};
    for(i=0;i<15;i++)for(j=0;j<40;j+=2)
    {a[i][j]=32;a[i][j+1]=32;}
    for(i=0;i<40;i+=2)
    {a[0][i]=-95;a[0][i+1]=-10;
    a[14][i]=-95;a[14][i+1]=-10;}
    for(i=0;i<15;i++)
    puts(a[i]);
    gotoxy(50,5);
    printf("愤怒的小球");
    gotoxy(50,7);
    printf("按w跳");
    while(1)
    {
        Sleep(200);
        m++;
        m=m%3;
        if(!m)
        {
        for(i=0;i<14;i++)
            for(j=0;j<38;j+=2)
            {a[i][j]=a[i][j+2];
            a[i][j+1]=a[i][j+3];}
            k++;
            k=k%4;
        if(!k)
        {
            z=rand()%11+1;
            for(i=0;i<15;i++)
            {
                if(z!=i&&i!=z+1&&i!=z+2){a[i][38]=-95;a[i][39]=-10;}
                else{a[i][38]=32;a[i][39]=32;}
            }
        }
        else
        {
            a[0][38]=-95;a[0][39]=-10;a[14][38]=-95;a[14][39]=-10;
            for(i=1;i<14;i++)
            {a[i][38]=32;a[i][39]=32;}
        }
        gotoxy(0,0);
        for(i=0;i<15;i++)
            puts(a[i]);
        }
        if(kbhit())
        {
            sh=getch();
            l=0;
        }
        gotoxy(6,n);
        puts("  ");
        l++;
        l=l%3;
        if(l==0)sh='s';
        switch (sh)
            {
                case 'w': case 'W': n--;break;
                case 's': case 'S': n++;break;
                default :;
            }
        gotoxy(6,n);
        if(a[n][6]==-95)break;
        puts(p);
    }
    while(1){printf("GAME OVER");Sleep(100000);}
}
