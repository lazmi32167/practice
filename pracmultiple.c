#include<stdio.h>
#include<stdlib.h>
void multipelset(int a[],int b[],int m,int n,FILE*output3)
{
    int i=0,j=0;
    fprintf(output3,"A*B={");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            fprintf(output3,"(%d,%d)",a[i],b[j]);
        }
    }
    fprintf(output3,"}\n");
}
int main()
{
    FILE*file,*output3;
    file=fopen("unionlab.txt","r");
    output3=fopen("output3.txt","w");
    if(file==NULL)
    {
        printf("file don't exits\n");
    }
    else{
        int m,n;
        fscanf(file,"%d",&m);
        int *a=(int*)malloc(m*sizeof(int));
        if(a==NULL)
        {
            printf("memory allocation failed.\n");
        }
        for(int i=0;i<m;i++)
        {
            fscanf(file,"%d",&a[i]);
        }
        fscanf(file,"%d",&n);
        int *b=(int*)malloc(n*sizeof(int));
        if(b==NULL)
        {
            printf("memory allocation failed.\n");
        }
        for(int i=0;i<n;i++)
        {
            fscanf(file,"%d",&b[i]);
        }
        fclose(file);

        fprintf(output3,"A={");
        for(int i=0;i<m;i++)
        {
            fprintf(output3,"%d",a[i]);
        }
        fprintf(output3,"}\n");
        fprintf(output3,"B={");
        for(int i=0;i<n;i++)
        {
            fprintf(output3,"%d",b[i]);
        }
        fprintf(output3,"}\n");
        multipelset(a,b,m,n,output3);
        free(a);
        free(b);
        fclose(output3);
    }
    return 0;
}
