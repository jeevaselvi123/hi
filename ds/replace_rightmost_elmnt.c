#include<stdio.h>
int main(){
    int arr[10],n,i,temp,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int max_from_right=arr[n-1];
    arr[n-1]=-1;
    for(i=n-2;i>=0;i--){
        temp=arr[i];
        arr[i]=max_from_right;
        if(max_from_right<temp){
            max_from_right=temp;
        }
    }
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }



}