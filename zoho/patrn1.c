#include<stdio.h>
int main(){
    int i,j;
    int k,n=5;
    for(i=1;i<=n;i++){
        k=1;
        for(j=1;j<=(n*2);j++){
            if(j<=i){
             printf("%d",k);
             k++;
            }
            else if(j>i && j>(n*2)/2){
                k--;
                if(k>0)
                printf("%d",k);
            }
            else{
                printf(" ");
            }
           /* else if(j>i &&j<=n-i){
                printf("*");
            }
            else if(j>n/2 && j>i){
                k--;
                if(k>0)
                 printf("%d",k);
            }
            else{
                printf("-");
            }*/
        }
        printf("\n");
    }
}