#include<stdio.h>
#include<stdlib.h>

void union_set(int a[],int b[],int m,int n){
    int i=0,j=0;
    printf("AUB:{");
    while(i<m && j<n){
        if(a[i]<b[j]){
            printf(" %d,",a[i]);
            i++;
        }
        else if(a[i]>b[j]){
            printf(" %d,",b[j]);
            j++;
        }
        else if(a[i]==b[j]){
            printf(" %d,",b[j++]);
            i++;
        }
    }

    while(i<m){
        printf(" %d,",a[i]);
        i++;
    }
    while(j<n){
        printf(" %d,",b[j]);
        j++;
    }
    printf("}\n");
}

int main(){
    FILE*file = fopen("unionlab.txt","r");

    if(file==NULL){
        printf("error file doesn't exist.\n");
        return 1;
    }
    else{
        int m, n;

        fscanf(file, "%d",&m);
        int *a=(int*)malloc(m* sizeof(int));
        if(a == NULL){
            printf("memorry allocation failed.\n");
            return 1;
        }
        for(int i=0; i<m; i++){
            fscanf(file,"%d",&a[i]);
        }

        fscanf(file, "%d",&n);
        int *b=(int*)malloc(n* sizeof(int));
        if(b == NULL){
            printf("memorry allocation failed.\n");
            return 1;
        }
        for(int i=0; i<n; i++){
            fscanf(file,"%d",&b[i]);
        }

        fclose(file);

        printf("A:{");
        for(int i=0; i<m; i++){
            printf(" %d,",a[i]);
        }
        printf("}\n");

        printf("B:{");
        for(int i=0; i<n; i++){
            printf(" %d,",b[i]);
        }
        printf("}\n");

        union_set(a,b,m,n);
        free(a);
        free(b);
    }
    return 0;
}
