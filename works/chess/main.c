#include <stdlib.h>
#include <string.h>
#include <windows.h>
static char a[4][9] =
    {

            " 3���ө�",
            " 2�ĩ��",
            " 1���۩�",
            "   A B C"
    };
static char u[4][9] =
    {

            " 3���ө�",
            " 2�ĩ��",
            " 1���۩�",
            "   A B C"
    };
static char p1[]="��";
    char p2[]="��";
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
static void wrong(char *x,int *y){
    while(!(*x>='A'&&*x<='C'&&*y>=1&&*y<=3))
    {
        gotoxy(0,4);
        printf("                           ");
        gotoxy(0,4);
        printf("��ʽ�����������룺");
        scanf(" %c %d",x,y);
    }
    while(a[3-*y][2*(*x-'A')+2]!=u[3-*y][2*(*x-'A')+2])
    {
        gotoxy(0,4);
        printf("                           ");
        gotoxy(0,4);
        printf("��λ�������壺");
        scanf(" %c %d",x,y);
    }
}
static int win(){
    int i,j;
    for(i=0;i<3;i++){
        if(a[i][2]==a[i][4]&&a[i][4]==a[i][6]&&a[i][3]==a[i][5]&&a[i][5]==a[i][7]
           ||a[0][2+2*i]==a[1][2+2*i]&&a[1][2+2*i]==a[2][2+2*i]
           &&a[0][2+2*i+1]==a[1][2+2*i+1]&&a[1][2+2*i+1]==a[2][2+2*i+1]){
            return 1;
        }
    }
    if(a[0][2]==a[1][4]&&a[1][4]==a[3][6]&&a[0][3]==a[1][5]&&a[1][5]==a[3][7]
       ||a[0][6]==a[1][4]&&a[1][4]==a[2][2]&&a[0][7]==a[1][5]&&a[1][5]==a[2][3])return 1;
    return 0;
}
int main()
{
    int i,h=0,y,k=1;
    char x;
    for(i=0;i<4;i++) puts(a[i]);
    gotoxy(30,h);puts("�����ʽ��A 1");
    while(1){
        gotoxy(0,4);
        printf("                           ");
        gotoxy(0,4);
     if(h%2==0){
        printf("�ڷ����������꣺");
        scanf(" %c %d",&x,&y);
        wrong(&x,&y);
        a[3-y][2*(x-'A')+2]=p1[0];
        a[3-y][2*(x-'A')+3]=p1[1];
        gotoxy(0,0);
        for(i=0;i<4;i++) puts(a[i]);
        if(win()){
            puts("");
            puts("�ڷ�ʤ");
            break;
        }
        h++;
        gotoxy(0,4);
        printf("                          ");
        gotoxy(0,4);
        gotoxy(30,h);printf("�ڷ����������Ϊ��%c %d",x,y);
     }
     else{
        printf("�׷����������꣺");
        scanf(" %c %d",&x,&y);
        wrong(&x,&y);
        a[3-y][2*(x-'A')+2]=p2[0];
        a[3-y][2*(x-'A')+3]=p2[1];
        gotoxy(0,0);
        for(i=0;i<4;i++) puts(a[i]);
        if(win()){
            puts("");
            puts("�׷�ʤ");
            break;
        }
        h++;
        gotoxy(0,4);
        printf("                          ");
        gotoxy(0,4);
        gotoxy(30,h);printf("�׷����������Ϊ��%c %d",x,y);
     }

    }
}




