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
        int rt;HideCursor(); //隐藏控制台的光标
        HWND hwnd=FindWindow("ConsoleWindowClass",NULL);/* 控制台窗口句柄 */
        hInput = GetStdHandle(STD_INPUT_HANDLE); /* 输入设备句柄 */
        while(1)
        {
             ReadConsoleInput(hInput, &inRec, 1, &numRead); /* 读取1个输入事件 */
             switch(inRec.EventType)
    {
        case MOUSE_EVENT:
            { rt=input(); switch(rt)
    {
       case 1:printf("%d %d\n",X,Y); break;
      break;
    }
            } break;
    }
        }
    }
