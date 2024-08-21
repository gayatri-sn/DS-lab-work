#include<stdio.h>

int main()
{
    int arr[10], i, n, key, mid;
    int flag = 0;
    printf("Enter number of elements in array: \n");
    scanf("%d",&n);
    printf("Enter elements of array:\n ");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter number to be searched:\n");
    scanf("%d",&key);
    int high = 0, low = n-1;
    mid = (high+low)/2;
    while(arr[high] <= arr[low]){
      mid = (high+low)/2;
      if(key == arr[mid]){
        flag = 1;
        printf("Number found at position %d",mid+1);
      break;
      }
      else if(key <= arr[mid]){
        low = mid - 1;
      }
      else if(key >= arr[mid])
        high = mid + 1;

    }

    if(flag==0)
        printf("Number not present in array.");
    return 0;
}
