#include<windows.h>
HANDLE hInput;/* ��ȡ��׼�����豸��� */
INPUT_RECORD inRec;/* �������ݼ�¼ */
DWORD numRead; /* �����Ѷ�ȡ�ļ�¼�� */
int Y,X;/* X��Y������ */
int input()
{
     while(1)
     {
         COORD pos = {0,0};ReadConsoleInput(hInput, &inRec, 1, &numRead);
 pos = inRec.Event.MouseEvent.dwMousePosition;Y=(int)pos.Y;X=(int)pos.X;

 if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
  /* ���������� */ return 1;

     }
}
 void HideCursor()//���ؿ���̨�Ĺ��
   { CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);}
    int main()
    {
        int rt;HideCursor(); //���ؿ���̨�Ĺ��
        HWND hwnd=FindWindow("ConsoleWindowClass",NULL);/* ����̨���ھ�� */
        hInput = GetStdHandle(STD_INPUT_HANDLE); /* �����豸��� */
        while(1)
        {
             ReadConsoleInput(hInput, &inRec, 1, &numRead); /* ��ȡ1�������¼� */
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
