#include<stdio.h>

int main()
{
    int arr[10],i,n,key;
    int flag = 0;
    printf("Enter number of elements in array: \n");
    scanf("%d",&n);
    printf("Enter elements of array:\n ");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter number to be searched:\n");
    scanf("%d",&key);
    for(i=0;i<n;i++){
        if(arr[i]==key){
            printf("Number present in array.\n");
            printf("Position: %d",i+1);
            flag = 1;
        }
    }
    if(flag==0)
        printf("Number not present in array.");
    return 0;
}
