#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

// This is for traversing a linklist and print it
void linklistTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Element : %d\n", ptr->data);        //This is used to prints the data in the linklist
        ptr = ptr -> next;          //This ptr is used to points an elements in the linklist when it becomes NULL it ends the loop
    }
};

// This is to insert the element in the linklist at first position
struct Node * insertAtFirst(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
};

// This is to insert the element in the linklist at End or last position
struct Node * insertAtEnd(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;

    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
};

// This is to insert the element at any index position in linklist
struct Node * insertAtIndex(struct Node * head, int data, int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;
    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;

};

// This is to insert the element after node in linklist
struct Node * insertAtAfterNode(struct Node * head, struct Node * prevNode, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;

};

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second node
    head -> data = 7;
    head -> next = second;

    // Link first and second node
    second -> data = 11;
    second -> next = third;

    // Link first and second node
    third -> data = 17;
    third -> next = fourth;

    // Link first and second node
    fourth -> data = 71;
    fourth -> next = NULL;


    printf("Linklist Before Insertion : \n");
    linklistTraversal(head);
    printf("\n");
    // head = insertAtFirst(head, 77);
    // head = insertAtIndex(head, 77, 1);
    // head = insertAtEnd(head, 77);
    head = insertAtAfterNode(head, third,77);  //Inserting element at third index after a node
    printf("Linklist After Insertion : \n");
    linklistTraversal(head);
    return 0;
}