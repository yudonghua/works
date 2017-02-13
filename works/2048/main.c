#include <windows.h>
int main()
{
    int a[4][4]={0},i,j,l,k=0,g=3;
    char sh;

   for(i=0;i<4;i++)for(j=0;j<4;j++)a[i][j]=0;
   while(1)
   {
                while(1)
                {i=rand()%4;j=rand()%4;
             if(a[i][j]==0){a[i][j]=2;break;}
                }
                for(i=0;i<4;i++)
          {   printf("  ʮ      ʮ       ʮ       ʮ       ʮ");
              printf("\n\n");
              for(j=0;j<4;j++)
              if(a[i][j]==0)printf("         ",a[i][j]);
              else if(a[i][j]>=10)printf("      %d ",a[i][j]);
              else if(a[i][j]>=100)printf("    %d  ",a[i][j]);
              else
              printf("      %d  ",a[i][j]);
              printf("\n\n");
          }printf("  ʮ      ʮ       ʮ       ʮ       ʮ");

                 sh=getch();switch (sh)
          {
           case 'w': case 'W':
           for(i=0;i<4;i++)
               {
                  for(j=0;j<4;j++)if(a[j][i]!=0)
                  {
                      if(a[k][i]==a[j][i]){k++;continue;}
                      a[k][i]=a[j][i];
                      k++;
                  }
               //   printf("%d\n",k);
                  for(j=k;j<4;j++)a[j][i]=0;
                  for(j=0;j<k-1;j++)
                  if(a[j][i]==a[j+1][i])
                  {
                      a[j][i]*=2;
                      for(l=j+1;l<k-1;l++)a[l][i]=a[l+1][i];
                      j--;k--;
                  }
                //      printf("%d\n",k);
                  for(j=k;j<4;j++)a[j][i]=0;
                  k=0;
               } break;
          case 's': case 'S':
          for(i=3;i>-1;i--)
               {
                  for(j=3;j>-1;j--)if(a[j][i]!=0)
                  {
                      if(a[g][i]==a[j][i]){g--;continue;}
                      a[g][i]=a[j][i];
                      g--;
                  }
                //  printf("%d\n",g);
                  for(j=g;j>-1;j--)a[j][i]=0;
                  for(j=3;j>g+1;j--)
                  if(a[j][i]==a[j-1][i])
                  {
                      a[j][i]*=2;
                      for(l=j-1;l>1;l--)a[l][i]=a[l-1][i];
                      j++;g++;
                  }
                //      printf("%d\n",k);
                  for(j=g;j>-1;j--)a[j][i]=0;
                  g=3;
               } break;
           case 'a': case 'A':
           for(i=0;i<4;i++)
               {
                  for(j=0;j<4;j++)if(a[i][j]!=0)
                  {
                      if(a[i][k]==a[i][j]){k++;continue;}
                      a[i][k]=a[i][j];
                      k++;
                  }
              //    printf("%d\n",k);
                  for(j=k;j<4;j++)a[i][j]=0;
                  for(j=0;j<k-1;j++)
                  if(a[i][j]==a[i][j+1])
                  {
                      a[i][j]*=2;
                      for(l=j+1;l<k-1;l++)a[i][l]=a[i][l+1];
                      j--;k--;
                  }
                //      printf("%d\n",k);
                  for(j=k;j<4;j++)a[i][j]=0;
                  k=0;
               } break;
           case 'd': case 'D':
           for(i=3;i>-1;i--)
               {
                  for(j=3;j>-1;j--)if(a[i][j]!=0)
                  {
                      if(a[i][g]==a[i][j]){g--;continue;}
                      a[i][g]=a[i][j];
                      g--;
                  }
              //    printf("%d\n",g);
                  for(j=g;j>-1;j--)a[i][j]=0;
                  for(j=3;j>g+1;j--)
                  if(a[i][j]==a[i][j-1])
                  {
                      a[i][j]*=2;
                      for(l=j-1;l>0;l--)a[i][l]=a[i][l-1];
                      j++;g++;
                  }
                //      printf("%d\n",k);
                  for(j=g;j>-1;j--)a[i][j]=0;
                  g=3;
               } break;
           default: ;
          }
          system("cls");



   }
}
