#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

// Define the structure for a student
struct Student {
    char name[MAX_NAME_LENGTH];
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

// Function to save student data to a text file
void saveToFile(struct Student* head, const char* fileName) {
    FILE* file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    while (head != NULL) {
        fprintf(file, "%s %d %.2f\n", head->name, head->roll, head->grades);
        head = head->next;
    }

    fclose(file);
    printf("Data saved to file successfully.\n");
}

// Function to load student data from a text file
void loadFromFile(struct Student** head, const char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    int roll;
    float grades;

    while (fscanf(file, "%s %d %f", name, &roll, &grades) == 3) {
        addStudent(head, name, roll, grades);
    }

    fclose(file);
    printf("Data loaded from file successfully.\n");
}

int main() {
    struct Student* studentList = NULL;

    int choice, roll;
    char name[MAX_NAME_LENGTH];
    float grades;

    const char* fileName = "project.txt";

    // Load existing data from file
    loadFromFile(&studentList, fileName);

    while (1) {
        printf("\n1. Add Student\n2. Display Students\n

