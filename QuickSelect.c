#include<stdio.h>

int partition(int *arr,int p,int r)
{
    int x=arr[r],i=p-1,j,temp;

    for(j=p;j<=r-1;j++)
    {
        if(arr[j]<=x)
        {
            i=i+1;
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }

    temp=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=temp;

    return i+1;
}

int KSmallest(int *arr,int p,int r,int k)
{
    if(k>0 && k-1<=r)
    {
        int pos=partition(arr,p,r);

        if(pos == k-1)
            return arr[pos];

        if(pos > k-1)
            return KSmallest(arr,p,pos-1,k);

        return KSmallest(arr,pos+1,r,k);
    }

    return -1;
}
int main()
{
    int arr[]={12,3,5,7,4,19,26},n=7,k=6;
    
    printf("The kth smallest element is %d",KSmallest(arr,0,n-1,k));
}
