#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<stdlib.h>
// ��ȡ����̨���ھ�� ΢��ٷ���վ�ĳ��� ֱ����������
HWND GetConsoleHwnd(void)
{
#define MY_BUFSIZE 1024 // Buffer size for console window titles.
 HWND hwndFound; // This is what is returned to the caller.
 char pszNewWindowTitle[MY_BUFSIZE]; // Contains fabricated
 char pszOldWindowTitle[MY_BUFSIZE]; // Contains original

 GetConsoleTitle(pszOldWindowTitle, MY_BUFSIZE);//��ȡ����̨�������pszOldWindowTitle��
 //���ÿ���̨�ı���Ϊ ʱ���� ����ID
 wsprintf(pszNewWindowTitle,"%d/%d",//�ѻ�ȡ����Ŀ���͵�ǰ����ID�����������pszNewwindowtitle��
 GetTickCount(),//���ڻ�ȡ����ϵͳ������ĺ�����
 GetCurrentProcessId());//��ȡ��ǰ����ID

 SetConsoleTitle(pszNewWindowTitle);//���Ŀ���̨�ı���Ϊ������

 Sleep(40);

 hwndFound=FindWindow(NULL, pszNewWindowTitle);//��ȡ����̨��HWND��

 SetConsoleTitle(pszOldWindowTitle);//���Ŀ���̨�ı���Ϊԭʼ����

 return(hwndFound);//���ؾ��
}
void drawXY()//����X��Y��
{
HWND hWnd=GetConsoleHwnd();//��ȡ����̨���ھ�����������û�����ɫ
HDC hDC=GetDC(hWnd);
COORD dwSize;//��¼�����С�������趨������Զ��
HPEN hNewPen=CreatePen(PS_SOLID,1,RGB(255,0,0));//�������ʶ���
HPEN hOldPen=(HPEN)SelectObject(hDC,hNewPen);//ѡȡ���ʶ�����л�ͼ
CONSOLE_SCREEN_BUFFER_INFO bInfo; // ������Ϣ
HANDLE Hout=GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ����̨���
GetConsoleScreenBufferInfo(Hout, &bInfo );//��ȡ����̨��Ϣ
dwSize=bInfo.dwMaximumWindowSize ;//��ȡ���ڴ�С,��ʱ��õ����ַ�ģʽ��
//���ַ���ͼ��Ŵ�������8��
dwSize.X *=8;
dwSize.Y*=8;
SetBkMode(hDC, TRANSPARENT);SetTextColor(hDC,255*255);
//����X�������������
TextOut(hDC,dwSize.X-15,dwSize.Y/2-15,"X",1);
//Arc(hDC,100,100,300,300,350,500,350,500);//��Բ ����hDC��ʾ��ͼ�����100��100��300��300��ʾ��ʹ�õľ�������350��500��ʾ�����ߵ���㣬350��500���������ߵ��յ� ;
//����Y�������������
TextOut(hDC,dwSize.X/2,0,"Y",1);
MoveToEx(hDC,0,dwSize.Y /2,NULL);
LineTo(hDC,dwSize.X,dwSize.Y/2);
MoveToEx(hDC,dwSize.X/2,0,NULL);
LineTo(hDC,dwSize.X/2,dwSize.Y);
ReleaseDC(hWnd,hDC);
}
void draw(double p)
{
int i;
double x,y;
HWND hWnd=GetConsoleHwnd();//��ȡ����̨���ھ�����������û�����ɫ
HDC hDC=GetDC(hWnd);
COORD dwSize;//��¼�����С�������趨������Զ��
HPEN hNewPen=CreatePen(PS_SOLID,1,RGB(255,0,0));//�������ʶ���
HPEN hOldPen=(HPEN)SelectObject(hDC,hNewPen);//ѡȡ���ʶ�����л�ͼ
CONSOLE_SCREEN_BUFFER_INFO bInfo; // ������Ϣ
HANDLE Hout=GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ����̨���
GetConsoleScreenBufferInfo(Hout, &bInfo );//��ȡ����̨��Ϣ
dwSize=bInfo.dwMaximumWindowSize ;//��ȡ���ڴ�С,��ʱ��õ����ַ�ģʽ��
//���ַ���ͼ��Ŵ�������8��
dwSize.X *=8;
dwSize.Y*=8;
//MoveToEx(hDC,0,dwSize.Y/2,NULL);
for(i=-180;i<=180;i++)
{
x=16*pow(sin(i*3.1415926/180),3.0)*p;
y=(13*cos(i*3.1415926/180)-5*cos(2*i*3.1415926/180)-2*cos(3*i*3.1415926/180)-cos(4*i*3.1415926/180))*p;
x=(x+16)*dwSize.X/32/2+dwSize.X/4;
 y=-y/16*dwSize.Y/2.3+dwSize.Y/2;
x=x;
y=y;
MoveToEx(hDC,x,y,NULL);
LineTo(hDC,x+1,y+1);
}
}
void main()
{
 double p;
drawXY();
for(p=0.6;p<=1;p=p+0.01)
draw(p);
system("PAUSE");
}
