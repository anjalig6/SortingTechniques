#include<stdio.h>
int main()
{
int n;
printf("Enter the size and elements of array resp.");
scanf("%d",&n);

int arr[n+1],temp,i,k,exchange=0,pass;
for(i=1;i<=n;i++)
scanf("%d",&arr[i]);
printf("Enter the pass");
scanf("%d",&pass);

 for(k=0;k<n;k++)
    {
      for(i=1;i<=n-k;i++)
        {
         if(arr[i]>arr[i+1])
         {
         temp=arr[i];
         arr[i]=arr[i+1];
         arr[i+1]=temp;
         exchange++;
         }
        }
     if(k==pass)
        {
        printf("After fifth Pass\n");
        for(i=1;i<=n;i++)
        printf("%d\n",arr[i]);
        }
     if(exchange==3)
        {
        printf("After tenth exchange\n");
        for(i=1;i<=n;i++)
        printf("%d\n",arr[i]);
        }
}
printf("Sorted Array");
for(i=1;i<=n;i++)
printf("%d",arr[i]);
}
