#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

struct StudentGradeChecker {
    char* students[MAX_STUDENTS];
    char* grades[MAX_STUDENTS];
    int count;
};

void initStudentGradeChecker(struct StudentGradeChecker* checker) {
    checker->count = 0;
}

char* getGrade(struct StudentGradeChecker* checker, char* studentName) {
    for (int i = 0; i < checker->count; ++i) {
        if (strcmp(checker->students[i], studentName) == 0) {
            return checker->grades[i];
        }
    }
    return "Student not found.";
}

void addStudent(struct StudentGradeChecker* checker, char* studentName, char* grade) {
    if (checker->count < MAX_STUDENTS) {
        checker->students[checker->count] = strdup(studentName);
        checker->grades[checker->count] = strdup(grade);
        ++checker->count;
        printf("%s added with a grade of %s.\n", studentName, grade);
    } else {
        printf("Cannot add more students. Maximum limit reached.\n");
    }
}

void updateGrade(struct StudentGradeChecker* checker, char* studentName, char* newGrade) {
    for (int i = 0; i < checker->count; ++i) {
        if (strcmp(checker->students[i], studentName) == 0) {
            free(checker->grades[i]);
            checker->grades[i] = strdup(newGrade);
            printf("%s's grade updated to %s.\n", studentName, newGrade);
            return;
        }
    }
    printf("Student not found.\n");
}

void displayGrades(struct StudentGradeChecker* checker) {
    printf("Student Grades:\n");
    for (int i = 0; i < checker->count; ++i) {
        printf("%s: %s\n", checker->students[i], checker->grades[i]);
    }
}

int main() {
    struct StudentGradeChecker gradeChecker;
    initStudentGradeChecker(&gradeChecker);

    // Example usage
    addStudent(&gradeChecker, "Alice", "A");
    addStudent(&gradeChecker, "Bob", "B");
    addStudent(&gradeChecker, "Charlie", "C");
    addStudent(&gradeChecker, "David", "A");

    // Display initial grades
    displayGrades(&gradeChecker);

    // Get a grade
    printf("\nGrade for Alice: %s\n", getGrade(&gradeChecker, "Alice"));

    // Add a new student
    addStudent(&gradeChecker, "Eve", "B");

    // Update a grade
    updateGrade(&gradeChecker, "Bob", "A");

    // Display updated grades
    displayGrades(&gradeChecker);

    // Free allocated memory
    for (int i = 0; i < gradeChecker.count; ++i) {
        free(gradeChecker.students[i]);
        free(gradeChecker.grades[i]);
    }

    return 0;
}
