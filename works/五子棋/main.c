#include<windows.h>
HANDLE hInput;/* 获取标准输入设备句柄 */
INPUT_RECORD inRec;/* 返回数据记录 */
DWORD numRead; /* 返回已读取的记录数 */
int Y,X;/* X和Y的坐标 */
int input()
{
     while(1)
     {
         COORD pos = {0,0};ReadConsoleInput(hInput, &inRec, 1, &numRead);
 pos = inRec.Event.MouseEvent.dwMousePosition;Y=(int)pos.Y;X=(int)pos.X;

 if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
  /* 鼠标左键单击 */ return 1;

     }
}
 void HideCursor()//隐藏控制台的光标
   { CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);}
    int main()
    {
         char p[4]="●◎";
    char a[15][31] =
 {
		"┏┯┯┯┯┯┯┯┯┯┯┯┯┯┓",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┗┷┷┷┷┷┷┷┷┷┷┷┷┷┛"
 };
        int x,y,i,rt;
   //     HideCursor(); //隐藏控制台的光标
   //     HWND hwnd=FindWindow("ConsoleWindowClass",NULL);/* 控制台窗口句柄 */
     //   hInput = GetStdHandle(STD_INPUT_HANDLE); /* 输入设备句柄 */
        for(i=0;i<15;i++)
            puts(a[i]);
        while(1)
        {
             ReadConsoleInput(hInput, &inRec, 1, &numRead); /* 读取1个输入事件 */
             switch(inRec.EventType)
    {
        case MOUSE_EVENT:
            { rt=input(); switch(rt)
    {
       case 1:x=Y;y=X; printf("%d %d",x,y);break;
      break;
    }
            } break;

    }
   // printf("%d %d",x,y);
   //  a[x][y]=p[0][1];a[x][y+1]=p[0][1];
            for(i=0;i<15;i++)
            puts(a[i]);
        }
    }
