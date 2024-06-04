#include<stdio.h>
//global structure
struct person
    {
        int age;
        float salary;
    };
int main()
{
    struct person person1,person2;
    person1.age=27;
    person1.salary=1250.50;
    printf("Person 1 : \n");
    printf("Age =%d\n",person1.age);
    printf("Salay =%.2f\n",person1.salary);
    person2.age=27;
    person2.salary=1250.50;
    printf("Person 2 : \n");
    printf("Age =%d\n",person2.age);
    printf("Salay =%.2f\n",person2.salary);
    return 0;

}
