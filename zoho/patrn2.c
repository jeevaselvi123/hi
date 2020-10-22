#include<stdio.h>
int main(){
    int i,j,n=5,k;
    for(i=n;i>0;i--){
        k=1;
        for(j=1;j<=(n*2)-1;j++){
            if(j>=i&&j<=(n*2)/2){
                printf("%d",k);
                k++;
            }
            else if(j>=(n*2)/2){
                k-=1;
            }
            else if(k>0 && j>((n*2)/2)-1){
                k-=1;
                if(k>0)
                printf("%d",k);
            }
            else{
                printf("*");
            }
        }
        printf("\n");
    }
}