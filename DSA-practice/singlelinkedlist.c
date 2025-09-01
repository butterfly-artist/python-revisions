#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void display_list(Node *head) {
    Node *ptr = head;
    if (ptr == NULL) {
        printf("List is empty\n");
    } else {
        while (ptr != NULL) {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int search(Node *head, int key) {
    Node *ptr = head;
    while (ptr != NULL) {
        if (ptr->data == key)
            return 1;
        ptr = ptr->next;
    }
    return 0;
}

int count(Node *head) {
    int cnt = 0;
    Node *ptr = head;
    while (ptr != NULL) {
        cnt++;
        ptr = ptr->next;
    }
    return cnt;
}

Node *insertAtEnd(Node *head, int value) {
    Node *n = createNode(value);
    if (head == NULL) {
        return n;
    }
    Node *lastNode = head;
    while (lastNode->next != NULL)
        lastNode = lastNode->next;
    lastNode->next = n;
    return head;
}

Node *AddAtBegin(Node *head, int value) {
    Node *n = createNode(value);
    n->next = head;
    return n;
}

Node *insertAtPosition(Node *head, int value, int position) {
    int len = count(head);
    if (position <= 1 || head == NULL) {
        printf("Inserting at beginning\n");
        return AddAtBegin(head, value);
    } else if (position > len) {
        printf("Inserting at end\n");
        return insertAtEnd(head, value);
    } else {
        Node *n = createNode(value);
        Node *ptr = head;
        for (int i = 1; i < position - 1; i++) {
            ptr = ptr->next;
        }
        n->next = ptr->next;
        ptr->next = n;
        return head;
    }
}

Node *deleteAtBegin(Node *head) {
    if (head == NULL) {
        printf("Cannot delete, list is empty\n");
        return NULL;
    }
    Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

Node *deleteAtEnd(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node *ptr = head;
    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
    return head;
}

int main() {
    Node *head = NULL;
    int choice, KEYSET, valueSET, position1, valueSET2, valueSET3;

    do {
        printf("\nMenu\n");
        printf("1. Insert at End\n");
        printf("2. Display List\n");
        printf("3. Search Element\n");
        printf("4. Insert at Position\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Add at Beginning\n");
        printf("8. Count\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &valueSET);
                head = insertAtEnd(head, valueSET);
                break;
            case 2:
                display_list(head);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &KEYSET);
                if (search(head, KEYSET)) {
                    printf("Key found in the list\n");
                } else {
                    printf("Key not found\n");
                }
                break;
            case 4:
                printf("Enter position to insert at: ");
                scanf("%d", &position1);
                printf("Enter value to insert: ");
                scanf("%d", &valueSET2);
                head = insertAtPosition(head, valueSET2, position1);
                break;
            case 5:
                head = deleteAtBegin(head);
                break;
            case 6:
                head = deleteAtEnd(head);
                break;
            case 7:
                printf("Enter value to insert: ");
                scanf("%d", &valueSET3);
                head = AddAtBegin(head, valueSET3);
                break;
            case 8:
                printf("Count: %d\n", count(head));
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 9);

    return 0;
}
