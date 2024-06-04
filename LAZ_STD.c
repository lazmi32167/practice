#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student
struct Student {
    char name[50];
    int roll;
    float grades;
    struct Student* next;
};

// Function to create a new student node
struct Student* createStudent(char name[], int roll, float grades) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    strcpy(newStudent->name, name);
    newStudent->roll = roll;
    newStudent->grades = grades;
    newStudent->next = NULL;
    return newStudent;
}

// Function to add a student to the linked list
void addStudent(struct Student** head, char name[], int roll, float grades) {
    struct Student* newStudent = createStudent(name, roll, grades);
    newStudent->next = *head;
    *head = newStudent;
    printf("Student added successfully.\n");
}

// Function to display all students in the linked list
void displayStudents(struct Student* head) {
    if (!head) {
        printf("No students in the list.\n");
        return;
    }

    printf("Student Information:\n");
    while (head != NULL) {
        printf("Name: %s, Roll: %d, Grades: %.2f\n", head->name, head->roll, head->grades);
        head = head->next;
    }
}

// Function to search for a student by roll number
struct Student* findStudent(struct Student* head, int roll) {
    while (head != NULL) {
        if (head->roll == roll) {
            return head;
        }
        head = head->next;
    }
    return NULL; // Student not found
}

// Function to remove a student from the linked list
void removeStudent(struct Student** head, int roll) {
    struct Student* current = *head;
    struct Student* prev = NULL;

    while (current != NULL && current->roll != roll) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Student not found.\n");
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Student removed successfully.\n");
}

// Function to update grades of a student
void updateGrades(struct Student* student, float newGrades) {
    student->grades = newGrades;
    printf("Grades updated successfully.\n");
}

// Function to free memory allocated for the linked list
void freeList(struct Student* head) {
    struct Student* current = head;
    struct Student* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct Student* studentList = NULL;

    int choice, roll;
    char name[50];
    float grades;

    while (1) {
        printf("\n1. Add Student\n2. Display Students\n3. Find Student\n");
        printf("4. Remove Student\n5. Update Grades\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter roll number: ");
                scanf("%d", &roll);
                printf("Enter grades: ");
                scanf("%f", &grades);
                addStudent(&studentList, name, roll, grades);
                break;

            case 2:
                displayStudents(studentList);
                break;

            case 3:
                printf("Enter roll number to find: ");
                scanf("%d", &roll);
                struct Student* foundStudent = findStudent(studentList, roll);
                if (foundStudent != NULL) {
                    printf("Student found - Name: %s, Roll: %d, Grades: %.2f\n",
                           foundStudent->name, foundStudent->roll, foundStudent->grades);
                } else {
                    printf("Student not found.\n");
                }
                break;

            case 4:
                printf("Enter roll number to remove: ");
                scanf("%d", &roll);
                removeStudent(&studentList, roll);
                break;

            case 5:
                printf("Enter roll number to update grades: ");
                scanf("%d", &roll);
                struct Student* studentToUpdate = findStudent(studentList, roll);
                if (studentToUpdate != NULL) {
                    printf("Enter new grades: ");
                    scanf("%f", &grades);
                    updateGrades(studentToUpdate, grades);
                } else {
                    printf("Student not found.\n");
                }
                break;

            case 6:
                freeList(studentList); // Free allocated memory before exiting
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
