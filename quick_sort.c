#include<stdio.h>
#include<stdlib.h>

void quick_sort(int *arr,int p,int r)
{
    int q;
    if(p<r)
    {
        q=partition(arr,p,r);
        quick_sort(arr,p,q-1);
        quick_sort(arr,q+1,r);
    }
}

int partition(int *arr,int p,int r)
{
    int x=arr[r],i=p-1,temp,j;

    for(j=p;j<=r-1;j++)
    {
        if(arr[j]<=x)
        {
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    
    temp=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=temp;

    return i+1;
}
int main()
{
    int i,size;

    printf("Enter the size and the elements of array");

    scanf("%d",&size);

    int *arr=(int *)malloc(sizeof(int));

    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    quick_sort(arr,0,size-1);

    for(i=0;i<size;i++)
    {
        printf("%d",arr[i]);
    }
}
