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
    for(i=1;i<n;i++){
        for(j=i; j>0 && arr[j-1] > arr[j];j--){
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;

        }
    }

    printf("Sorted array is: \n");
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}
