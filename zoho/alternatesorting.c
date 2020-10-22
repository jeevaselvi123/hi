#include<stdio.h>
#include<string.h>
int big=0,small=0;
//return the smallest number
int smallfun(int arr[],int n){
    int i,j,temp;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
           if(arr[i]>arr[j]){
               temp=arr[i];
               arr[i]=arr[j];
               arr[j]=temp;
           }
        }
    }
    return arr[small++];
}
//return the biggest number 
int bigfun(int arr[],int n){
    int i,j,temp;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
           if(arr[i]<arr[j]){
               temp=arr[i];
               arr[i]=arr[j];
               arr[j]=temp;
           }
        }
    }
    return arr[big++];
}
int main(){
    int i,j,n,arr[100],res[100];
    printf("Enter the size of the array:\t");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        if(i%2==0){
           res[i]= bigfun(arr,n);
        }
        else{
           res[i]= smallfun(arr,n);
        }
    }
    printf("Alternate sorting:\n");
    for(i=0;i<n;i++){
        printf("%d\t",res[i]);
    }
   

}