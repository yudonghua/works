#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#define I 10
#define R 170
void color(const unsigned short color1)
{
    if(color1>=0&&color1<=15)
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
    else
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

char sh;
char h[250]={"曾经\n有一份真挚的爱情摆在我面前\n我没有珍惜\n等到我失去的时候才后悔莫及\n人世间最痛苦的事莫过于此......\n如果上天能够给我一个再来一次的机会\n我会对那个女孩子说三个字\n“我爱你。”\n如果非要在这份爱上加一个期限，\n我希望是.....一万年！\n"};
int main()
{
    int r;
    char ch;
    while(1)
    {
        system("cls");
        color(7);
    printf("按1(v)或2(g)");
    ch=getch();
    if(ch=='1'||ch=='g')
    shu();
    if(ch=='2'||ch=='g')
    aixin();

    }

}
shu ()
{

        int i;
        system("cls");
       for(i=0;i<250;i++)
       {
          Sleep(20);system("color c");color(rand()%16); printf("%c",h[i]);
       }

}
aixin()
{
int i,j,e,z;
   int a;
   system("cls");
   for(i=1,a=I;i<I/2;i++,a--){
       for(j=I-sqrt(I*I-(a-i)*(a-i));j>0;j--)
           printf(" ");
       for(e=1;e<=sqrt(I*I-(a-i)*(a-i));e++)
           {Sleep(10);color(e%16);printf("\3");}
           z=2*sqrt(I*I-(a-i)*(a-i));
       for(;e<=2*sqrt(I*I-(a-i)*(a-i));e++)
           {Sleep(10);color((z-e)%16);printf("\3");}
for(j=2*( I-sqrt(I*I-(a-i)*(a-i)) );j>0;j--)
           printf(" ");
for(e=1;e<=sqrt(I*I-(a-i)*(a-i));e++)
           {Sleep(10);color(e%16);printf("\3");}
           for(;e<=2*sqrt(I*I-(a-i)*(a-i));e++)
           {Sleep(10);color((z-e)%16);printf("\3");}
    printf("\n");
   }
   for(i=1;i<39;i++)
   {
if(i==12){
printf("  I LOVE YOU!  ");
i+=15;
         }
color(4);printf("\3");
   }
   printf("\n");

   for(i=1;i<=R/2;i++){
       if(i%2||i%3)continue;
       for(j=R-sqrt(R*R-i*i);j>0;j--)
           printf(" ");
       for(e=1;e<=( sqrt(R*R-i*i) - (R-2*I) );e++)
           {Sleep(10);color(e%16);printf("\3");}
           z=2*( sqrt(R*R-i*i) - (R-2*I) );
           for(;e<=2*( sqrt(R*R-i*i) - (R-2*I) );e++)
           {Sleep(10);color((z-e)%16);printf("\3");}
       printf("\n");
   }
   Sleep(4000);
   return 0;
}
