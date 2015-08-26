#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    int i,j,k,ptr,temp,arg[2];
    long int t[2];
    struct timeval t1,t2;

    for(i=1,j=0;i<argc;i++,j++)
    {
        sscanf(argv[i],"%d",&arg[j]);
    }

    for(k=0;k<2;k++)
    {
        int size=arg[k];
        int *n=(int*)malloc(size*sizeof(int));
        
        if(k==0)
        {
            for(i=0;i<size;i++)
            {
                n[i]=i;
            }
        }    
        
        if(k==1)
        {
            for(i=0;i<size;i++)
            {
                n[i]=rand()%size;
            }
        }
        
        gettimeofday(&t1,NULL);

        for(i=1;i<size;i++)
        {
            temp=n[i];ptr=i-1;
    
            while(temp<n[ptr]&&ptr>=0)
            {
                n[ptr+1]=n[ptr];
                ptr=ptr-1;
            }
            n[ptr+1]=temp;
        } 

        gettimeofday(&t2,NULL);
        
        t[k]=(t2.tv_sec*(1000000)+t2.tv_usec)-(t1.tv_sec*(1000000)+t1.tv_usec);
        printf("Time is %ld \n",t[k]);
       }
}
