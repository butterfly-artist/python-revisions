#include <stdio.h>

#define SIZE 5

int stack[SIZE];
int top = -1;

int isFull() {
    if (top == SIZE - 1) {
        printf("Stack is full\n");
        return 1;
    } else {
        printf("Stack is not full\n");
        return 0;
    }
}

int isEmpty() {
    if (top == -1) {
        printf("Stack is empty\n");
        return 1;
    } else {
        printf("Stack has some values\n");
        return 0;
    }
}

int peek() {
    if (!isEmpty()) {
        return stack[top];
    } else {
        return -1; // Indicates empty stack
    }
}

int length() {
    return top + 1;
}

void push(int value) {
    if (isFull()) {
        printf("Cannot push %d, stack is full\n", value);
    } else {
        stack[++top] = value;
        printf("Pushed %d\n", value);
    }
}

void pop() {
    if (isEmpty()) {
        printf("Cannot pop, stack is empty\n");
    } else {
        printf("Popped %d\n", stack[top--]);
    }
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    display();

    pop();
    display();

    printf("Top element is: %d\n", peek());
    isEmpty();
    isFull();
    printf("Stack length is: %d\n", length());

    return 0;
}
