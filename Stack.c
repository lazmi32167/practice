#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Function to initialize an empty stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
bool isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
    } else {
        stack->items[++stack->top] = value;
        printf("%d pushed to the stack\n", value);
    }
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1; // Return a sentinel value indicating an error
    } else {
        return stack->items[stack->top--];
    }
}

// Function to peek at the top element of the stack
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; // Return a sentinel value indicating an error
    } else {
        return stack->items[stack->top];
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    printf("Top element after pops: %d\n", peek(&stack));

    return 0;
}

