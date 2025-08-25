#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node * next;
}Node;
//struct Node a;
//Node *ptr=(Node *)malloc(sizeof(Node));
void display_list(Node *head){
	Node *ptr=head;
	if(ptr==NULL){
		printf("list is empty");
	}
	else{
		while(ptr != NULL){
			printf("%d ->",ptr->data);
			ptr = ptr -> next;
		}
printf("null");
	}
}
Node * createNode(int value){
	Node * newNode;
	newNode = (Node *)malloc(sizeof(Node));
	newNode -> data =value;
	newNode ->next=NULL;
	return newNode;
}
int search(Node *head ,int key){
	Node * ptr =head;
	if (ptr==NULL){
		printf("lst is empty");
	}
	else{
		while(ptr!=NULL){
			if(ptr->data==key)
			return 1;
			ptr=ptr->next;
		}
	}return 0;
}
Node * insertAtEnd(Node * head, int value){
	Node * n = createNode(value);
	if(head==NULL){
		head=n;
	}
	else{
		Node * lastNode =head;
		while(lastNode -> next != NULL)
		lastNode =lastNode ->next;
		lastNode ->next =n;
	}
	return head;
}




int main() {
    Node *head = NULL;
    int choice,KEYSET,valueSET;
   do {
        printf("\n Menu \n");
        printf("1. Insert at End\n");
        printf("2. Display List\n");
        printf("3. Search Element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &valueSET);
                head = insertAtEnd(head, valueSET);
                printf("Inserted %d at end.\n", valueSET);
                break;
            case 2:
                printf("Current List: ");
                display_list(head);
                printf("\n");
                break;
            case 3:
            	printf("search list");
            	scanf("%d",&KEYSET);
            	if(search(head,KEYSET)){
             	printf("key found in the list");
                 }else{
    	        printf("not found");
	        	}
	        	break;
	        case 4:
	        	printf("EXIT the commands");
	        	break;
	    }}while(choice!=4);

//    head = insertAtEnd(head, 10);
//    insertAtEnd(head, 20);
//    insertAtEnd(head, 30);
//    insertAtEnd(head, 55);
//    insertAtEnd(head, 70);
//    insertAtEnd(head, 60);
//    insertAtEnd(head, 234);
//    insertAtEnd(head, 97);
//    insertAtEnd(head, 623);
//    printf("List: ");
//    display_list(head);
//    search(head,60);
//    if(search(head,20)){
//    	printf("key found in the list");
//    }else{
//    	printf("not found");
//		}
  return 0;

}




