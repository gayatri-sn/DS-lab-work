#include<stdio.h>

int main()
{
    int arr[10],i,min,j,temp,n,key;
    int flag = 0;
    printf("Enter number of elements in array: \n");
    scanf("%d",&n);
    printf("Enter elements of array:\n ");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    for(i=0;i<n;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
               min = j;
            }
        }
        temp = arr[i];
        arr[i]= arr[min];
        arr[min]= temp;
    }
    printf("Sorted array is: \n");
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}
