#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void powerset(int a[],int m,FILE*output4)
{
    int sets=pow(2,m);
    for(int i=0;i<sets;i++)
    {
       fprintf(output4,"{");
       for(int j=0;j<m;j++)
       {
           if((1<<j)&i){
            fprintf(output4,"%d",a[j]);
           }
       }
       fprintf(output4,"}\n");

    }
}
int main()
{
    FILE*file,*output4;
    file=fopen("shokti.txt","r");
    output4=fopen("output4.txt","w");
    if(file==NULL)
    {
        printf("file don't exits\n");
    }
    else{
        int m;
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

        fclose(file);

        fprintf(output4,"A={");
        for(int i=0;i<m;i++)
        {
            fprintf(output4,"%d",a[i]);
        }
        fprintf(output4,"}\n");
        powerset(a,m,output4);
        free(a);
        fclose(output4);
    }
    return 0;
}

