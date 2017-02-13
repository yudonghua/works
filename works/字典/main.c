#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
    int x,chang,y,i;
    char ru[20],chu[20],yisi[60],zi;
    FILE*fp;

 if((fp=fopen("words.txt","r"))==NULL)
    {
      printf("sorry,no find\n");
      exit(1);
    }

 biaohao:printf("请输入要查询的单词\n");
    scanf("%s",ru);
    chang=strlen(ru);

    rewind(fp);
    fgets(chu,chang+1,fp);
    while(strcmp(chu,ru)!=0)
    {
      if(feof(fp))
       {
         printf("单词没找到......\n");
         goto biaohao;
       }

    for(;;)
        {
          if(fgetc(fp)=='\n')
              break;
       }
      fgets(chu,chang+1,fp);
     }

     fseek(fp,-(long)chang,1);
     for(y=0;(zi=fgetc(fp))!='\n';y++)
     {
       yisi[y]=zi;
     }
     yisi[y]='\0';

     printf("%s\n",yisi);

     zaibiaohao:printf("输入1继续查词，输入2清空屏幕，输入0退出程序\n");
     scanf("%d",&x);
     if(x==0)
      {
         exit(0);
      }
     if(x==1)
      {
        goto biaohao;
      }
     for(i=0;i<=100;i++)
      {
         printf("\n");
       }
   goto zaibiaohao;
}
