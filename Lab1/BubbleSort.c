#include<stdio.h>

int main()
{
    int arr[10],i,j,temp,n,key;
    int flag = 0;
    printf("Enter number of elements in array: \n");
    scanf("%d",&n);
    printf("Enter elements of array:\n ");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i]= arr[j];
                arr[j]= temp;
            }
        }
    }
    printf("Sorted array is: \n");
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}
