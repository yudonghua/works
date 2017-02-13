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
HANDLE hInput;
INPUT_RECORD inRec;
DWORD numRead;
int Y,X;
int input()
{
     while(1)
     {
         COORD pos = {0,0};ReadConsoleInput(hInput, &inRec, 1, &numRead);
 pos = inRec.Event.MouseEvent.dwMousePosition;Y=(int)pos.Y;X=(int)pos.X;

 if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
   return 1;

     }
}
void HideCursor()
   { CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);}
int main()
    {
        int i,rt,x,y,k=1;
        HideCursor();
    char a[16][36] =
{
		"15©³©Ó©Ó©Ó©Ó©Ó©Ó©Ó©Ó©Ó©Ó©Ó©Ó©Ó©·",
		"14©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
		"13©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
		"12©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
		"11©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
		"10©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
		" 9©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
		" 8©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
		" 7©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
		" 6©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
		" 5©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
		" 4©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
		" 3©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
		" 2©Ä©à©à©à©à©à©à©à©à©à©à©à©à©à©Ì",
		" 1©»©Û©Û©Û©Û©Û©Û©Û©Û©Û©Û©Û©Û©Û©¿",
		"   A B C D E F G H I J K L M N O"
};

char p1[]="¡ñ";
char p2[]="¡ò";
for(i=0;i<16;i++) puts(a[i]);
        HWND hwnd=FindWindow("ConsoleWindowClass",NULL);
        hInput = GetStdHandle(STD_INPUT_HANDLE);
        while(1)
        {
             ReadConsoleInput(hInput, &inRec, 1, &numRead);
             switch(inRec.EventType)
    {
        case MOUSE_EVENT:
            { rt=input(); switch(rt)
    {
       case 1:x=Y;y=X/2;break;
      break;
    }
            } break;
    }

       if(k%2==0)
       {
         if(x>=0&&x<15&&y>0&&y<16)
         {
           a[x][2*y]=p1[0];a[x][2*y+1]=p1[1];
           gotoxy(0,0);
           for(i=0;i<16;i++) puts(a[i]);
           k++;
         }
       }
    else
    {
     if(x>=0&&x<15&&y>0&&y<16)
     {
       a[x][2*y]=p2[0];a[x][2*y+1]=p2[1];
       gotoxy(0,0);
       for(i=0;i<16;i++) puts(a[i]);
       k++;
     }
    }

        }
    }



