#include<stdio.h>
#include<string.h>
int main(){
   int i,j;
   char str[10];
   printf("Enter the string:\t");
   scanf("%s",str);
   int n=strlen(str);
   for(i=0;i<n;i++){
       for(j=0;j<n;j++){
       if(i==j){
           printf("%c",str[i]);
       }
       else if(j==n-i-1){
           printf("%c",str[j]);
       }
       else
          printf("  "); 
        }
        printf("\n");
   }
}