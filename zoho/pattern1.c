#include<stdio.h>
#include<string.h>
int main(){
    int i,j;
    char s[10]="program";
    int n=strlen(s);
    for(i=0;i<strlen(s);i++){
        for(j=0;j<strlen(s);j++){
            if(i==j)
              printf("%c",s[i]);
            else if(j==n-i-1)
              printf("%c",s[j]);              
            else
              printf("  ");
        }
        printf("\n");
    }
}