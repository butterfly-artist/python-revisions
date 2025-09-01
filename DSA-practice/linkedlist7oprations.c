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
int count(Node * head){
	int count =0;
	Node * ptr=head;
	if(ptr==NULL){
		printf("nothing in the list");
	}
	else{
		while(ptr!=NULL){
			ptr=ptr->next;
			count++;
		}
	}
	return count;

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
Node * AddAtBegin(Node * head,int value){
	Node * n= createNode(value);
	n->next=head;
	head=n;
	return head;
}
Node * insertAtPosition(Node * head, int value, int position){
    int len=count(head);
	if(position>len){
		printf("inserting at end");
		insertAtEnd(head,value);
		return head;
	}
	else if(position==1||head==NULL){
		printf("inserting at beginning");
		AddAtBegin(head,value);
		return head;
	}
	else{
		Node * n=createNode(value);
			Node * ptr =head;
		for(int i=1;i<position-1;i++){
			ptr=ptr->next;
		}
		ptr->next=n->next;
		n=ptr->next;
		return head;
	}
		
}
Node * deleteAtBegin(Node * head){
	if(head==NULL){
		printf("cannot delete list is empty");
	}
	else{
		Node *ptr=head;
		head=ptr->next;
		ptr->next=NULL;
		free (ptr);
	}
	return head;
}
Node * deleteAtEnd(Node * head){
		Node * ptr =head;
	if(head==NULL){
		printf("list is empty");
	}
	else if(head->next==NULL){
		free(head);
		free(ptr);
	}
	else{
		int len=count(head);
		if(len>1){
			ptr=ptr->next;
			free(ptr->next);
			ptr->next=NULL;
		}
	}
	return head;
}

int main() {
    Node * head = NULL;
    int choice,KEYSET,valueSET,position1,valueSET2,valueSET3;
   do {
        printf("\n Menu \n");
        printf("1. Insert at End\n");
        printf("2. Display List\n");
        printf("3. Search Element\n");
        printf("4. insert at position\n");
        printf("5. Delete at begin\n");
        printf("6. delete at end\n");
        printf("7. Add at begining\n");
        printf("8. Count\n");
        printf("9. Exit\n");

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
	        	printf("insert at which position");
	        	scanf("%d",&position1);
	        	printf("Enter value to insert at position: ");
                scanf("%d", &valueSET2);
	        	insertAtPosition(head,valueSET2,position1);
	        	printf("Inserted at postion");
	        	break;
	        case 5:
	        	printf("Delete at beginning");
	        	deleteAtBegin(head);
	        	break;
	        case 6:
	        	printf("delete at end");
	        	deleteAtEnd(head);
	        	break;
	        case 7:
	        	printf("Add at beginning");
	        	printf("Enter value to insert: ");
                scanf("%d", &valueSET3);
                AddAtBegin(head,valueSET3);
	        	break;
	        case 8:
	        	printf("Count");
	        	count(head);
	        	break;
			case 9:
	        	printf("EXIT the commands");
	        	break;
	    }}while(choice!=9);

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



