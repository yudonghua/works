#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f,*fout;
    char b[10];
    if((f=fopen("test.txt","rt"))!=NULL){
        fgets(b,11,f);
    }
    fclose(f);
    if((fout=fopen("test2.txt","a+"))!=NULL){
        fputs(b,fout);
    }
}
