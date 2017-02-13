#include <stdio.h>
#include <windows.h>
#define NUM 10
int max=NUM,a[NUM],b[NUM]={1,1,1,1,1,1,1,1,1,1};
int main(){
    st(0);
}
void st(int n){
    int i=0,j;
    if(n==max){
        for(i=0;i<max;i++) {
            printf("%d ",a[i]);
        }
        printf("\n");
        return;
    }

    for(i=0;i<max;i++){

        if(!b[i])continue;
        b[i]--;
        a[n]=i;
        st(n+1);
        b[i]++;
    }
}
