#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

int main(int argc,char* argv[])
{
	int n[argc],i,j,l,loc,min,count=0,temp;
	float  tf[argc-1];
	long int t[argc],k;
	struct timeval t1,t2;

	for(i=1;i<argc;i++)
	{
		sscanf(argv[i],"%d",&n[i]);

		int *arr=(int *)malloc(n[i]*sizeof(int));	
		
		for(k=0;k<n[i];k++)
		{
			arr[k]=rand()%n[i];
		}
		
		gettimeofday(&t1,NULL);

		for(k=0;k<n[i];k++)
		{
			min=arr[k];
			loc=k;
			for(j=k;j<n[i];j++)
			{
				if(min>arr[j])
				{
				min=arr[j];
				loc=j;
				count=1;
				}
			}
			if(count==1)
			{
				temp=arr[k];
				arr[k]=arr[loc];
				arr[loc]=temp;
				count=0;
			}
		}
		
		gettimeofday(&t2,NULL);
		
		t[i]=((t2.tv_sec*(1000000))+t2.tv_usec)-((t1.tv_sec*(1000000))+t1.tv_usec);
		
	}

	for(l=1;l<argc-1;l++)
	{
		tf[l]=((float)t[l+1])/((float)t[l]);
		printf("%f\n ",tf[l]);
	}
}
