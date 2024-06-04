#include<stdio.h>
#include<stdlib.h>
void intersection(int )




int main()
{
    FILE*file;
    file=fopen("kisuparina.txt","r");
    if(file==NULL)
    {
        printf("file doesnot exits.\n");
    }
    else{
        int m,n;
        fscanf(file,"%d",&m);
        int *a=(int*)malloc(m*sizeof(int));
        if(a==NULL)
        {
            print("memory allocation failed\n");
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
            print("memory allocation failed\n");
            return 1;
        }

            for(int i=0;i<n;i++)
            {
                fscanf(file,"%d",&b[i]);
            }
    fclose(file);
    printf("A={");
    for(int i=0;i<m;i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");

    printf("B={");
    for(int i=0;i<n;i++)
    {
        printf("%d",b[i]);
    }
    printf("\n");
    intersection_set(a,b,m,n);
    free(a);
    free(b);
    }
    return 0;
}
