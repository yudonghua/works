#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<stdlib.h>
// 获取控制台窗口句柄 微软官方网站的程序 直接拿来用了
HWND GetConsoleHwnd(void)
{
#define MY_BUFSIZE 1024 // Buffer size for console window titles.
 HWND hwndFound; // This is what is returned to the caller.
 char pszNewWindowTitle[MY_BUFSIZE]; // Contains fabricated
 char pszOldWindowTitle[MY_BUFSIZE]; // Contains original

 GetConsoleTitle(pszOldWindowTitle, MY_BUFSIZE);//获取控制台标题存入pszOldWindowTitle中
 //设置控制台的标题为 时间数 进程ID
 wsprintf(pszNewWindowTitle,"%d/%d",//把获取的数目，和当前进程ID输出到缓冲区pszNewwindowtitle中
 GetTickCount(),//用于获取操作系统启动后的毫秒数
 GetCurrentProcessId());//获取当前进程ID

 SetConsoleTitle(pszNewWindowTitle);//更改控制台的标题为新内容

 Sleep(40);

 hwndFound=FindWindow(NULL, pszNewWindowTitle);//获取控制台的HWND号

 SetConsoleTitle(pszOldWindowTitle);//更改控制台的标题为原始内容

 return(hwndFound);//返回句柄
}
void drawXY()//绘制X和Y轴
{
HWND hWnd=GetConsoleHwnd();//获取控制台窗口句柄，用于设置画笔颜色
HDC hDC=GetDC(hWnd);
COORD dwSize;//记录窗体大小，用于设定坐标轴远点
HPEN hNewPen=CreatePen(PS_SOLID,1,RGB(255,0,0));//创建画笔对象
HPEN hOldPen=(HPEN)SelectObject(hDC,hNewPen);//选取画笔对象进行绘图
CONSOLE_SCREEN_BUFFER_INFO bInfo; // 窗口信息
HANDLE Hout=GetStdHandle(STD_OUTPUT_HANDLE);//获取控制台句柄
GetConsoleScreenBufferInfo(Hout, &bInfo );//获取控制台信息
dwSize=bInfo.dwMaximumWindowSize ;//获取窗口大小,此时获得的是字符模式下
//从字符到图像放大坐标轴8倍
dwSize.X *=8;
dwSize.Y*=8;
SetBkMode(hDC, TRANSPARENT);SetTextColor(hDC,255*255);
//绘制X轴各个特殊坐标
TextOut(hDC,dwSize.X-15,dwSize.Y/2-15,"X",1);
//Arc(hDC,100,100,300,300,350,500,350,500);//画圆 其中hDC表示画图句柄，100，100，300，300表示所使用的矩形区域，350，500表示画弧线的起点，350，500表明画弧线的终点 ;
//绘制Y轴各个特殊坐标
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
HWND hWnd=GetConsoleHwnd();//获取控制台窗口句柄，用于设置画笔颜色
HDC hDC=GetDC(hWnd);
COORD dwSize;//记录窗体大小，用于设定坐标轴远点
HPEN hNewPen=CreatePen(PS_SOLID,1,RGB(255,0,0));//创建画笔对象
HPEN hOldPen=(HPEN)SelectObject(hDC,hNewPen);//选取画笔对象进行绘图
CONSOLE_SCREEN_BUFFER_INFO bInfo; // 窗口信息
HANDLE Hout=GetStdHandle(STD_OUTPUT_HANDLE);//获取控制台句柄
GetConsoleScreenBufferInfo(Hout, &bInfo );//获取控制台信息
dwSize=bInfo.dwMaximumWindowSize ;//获取窗口大小,此时获得的是字符模式下
//从字符到图像放大坐标轴8倍
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
