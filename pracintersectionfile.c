#include<stdio.h>
#include<stdlib.h>
void intersection(int a[],int b[],int m,int n,FILE*output2)
{
    int i=0,j=0;
    fprintf(output2,"A∩B={");
    while(i<m && j<n){
     if(a[i]<b[j]){
        i++;
     }
     else if(a[i]>b[j]){
        j++;
     }
     else if(a[i]==b[j])
     {
        fprintf(output2,"%d",b[j++]);
        i++;
     }
    }
    fprintf(output2,"}\n");
}
int main()
{
    FILE*file,*output2;
    file=fopen("unionlab.txt","r");
    output2=fopen("output2.txt","w");
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

        fprintf(output2,"A={");
        for(int i=0;i<m;i++)
        {
            fprintf(output2,"%d",a[i]);
        }
        fprintf(output2,"}\n");
        fprintf(output2,"B={");
        for(int i=0;i<n;i++)
        {
            fprintf(output2,"%d",b[i]);
        }
        fprintf(output2,"}\n");
        intersection(a,b,m,n,output2);
        free(a);
        free(b);
        fclose(output2);
    }
    return 0;
}
