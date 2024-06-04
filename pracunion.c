#include<stdio.h>
#include<stdlib.h>
void unionset(int a[],int b[],int m,int n,FILE*output)
{
    int i=0,j=0;
    fprintf(output,"AUB={");
    while(i<m && j<n){
        if(a[i]<b[j]){
            fprintf(output," %d,",a[i]);
            i++;
        }
        else if(b[j]<a[i])
        {
            fprintf(output," %d,",b[j]);
            j++;
        }
        else if(a[i]==b[j])
        {
            fprintf(output," %d,",b[j++]);
            i++;
        }

    }
    while(i<m){
        fprintf(output," %d,",a[i]);
        i++;
    }
    while(j<n){
        fprintf(output," %d,",b[j]);
        j++;
    }
    fprintf(output,"}\n");
}
int main()
{
    FILE*file,*output;
    file=fopen("unionlab.txt","r");
    output=fopen("output.txt","w");
    if(file==NULL){
        printf("file doesnot exits.\n");
        return 0;
    }
    else{
        int m,n;
        fscanf(file,"%d",&m);
        int *a=(int*)malloc(m*sizeof(int));
        if(a==NULL)
        {
            printf("memory allocation failed\n");
            return 1;
        }

            for(int i=0;i<m;i++)
            {
                fscanf(file,"%d",&a[i]);
            }
        fscanf(file,"%d",&n);
        int *b=(int*)malloc(n*sizeof(int));
        if(b==NULL)
        {
            printf("memory allocation failed\n");
            return 1;
        }

            for(int i=0;i<n;i++)
            {
                fscanf(file,"%d",&b[i]);
            }
    fclose(file);
    fprintf(output,"A={");
    for(int i=0;i<m;i++)
    {
        fprintf(output,"%d ",a[i]);
    }
    fprintf(output,"}\n");

    fprintf(output,"B={");
    for(int i=0;i<n;i++)
    {
        fprintf(output,"%d ",b[i]);
    }
    fprintf(output,"}\n");
    unionset(a,b,m,n,output);
    free(a);
    free(b);
    fclose(output);
    }
    return 0;
}
