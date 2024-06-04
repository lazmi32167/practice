#include<stdio.h>
#include<stdlib.h>
void INterSection(int a[],int b[],int la,int em,FILE*output2)
{
    int x=0,y=0;
    fprintf(output2,"A∩B={");
    while(x<la && y<em){
     if(a[x]<b[y]){
        x++;
     }
     else if(a[x]>b[y]){
        y++;
     }
     else if(a[x]==b[y])
     {
        fprintf(output2,"%d ",b[y++]);
        x++;
     }
    }
    fprintf(output2,"}\n");
}
int main()
{
    FILE*filename,*output2;
    filename=fopen("intersectionlab.txt","r");
    output2=fopen("output2.txt","w");
    if(filename==NULL)
    {
        printf("file don't exit here\n");
    }
    else{
        int la,em;
        fscanf(filename,"%d",&la);
        int *a=(int*)malloc(la*sizeof(int));
        if(a==NULL)
        {
            printf("Memory allocation failed.\n");
        }
        for(int i=0;i<la;i++)
        {
            fscanf(filename,"%d",&a[i]);
        }
        fscanf(filename,"%d",&em);
        int *b=(int*)malloc(em*sizeof(int));
        if(b==NULL)
        {
            printf("Memory allocation failed.\n");
        }
        for(int i=0;i<em;i++)
        {
            fscanf(filename,"%d",&b[i]);
        }
        fclose(filename);

        fprintf(output2,"A={");
        for(int i=0;i<la;i++)
        {
            fprintf(output2,"%d,",a[i]);
        }
        fprintf(output2,"}\n");
        fprintf(output2,"B={");
        for(int i=0;i<em;i++)
        {
            fprintf(output2,"%d,",b[i]);
        }
        fprintf(output2,"}\n");
        INterSection(a,b,la,em,output2);
        free(a);
        free(b);
        fclose(output2);
    }
    return 0;
}

