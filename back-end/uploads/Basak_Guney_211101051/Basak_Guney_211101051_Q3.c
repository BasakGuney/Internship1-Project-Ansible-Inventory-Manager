#include <stdio.h>
#include <stdlib.h>


struct listNode{
    int data;
    struct listNode *nextPtr;
};
typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;


ListNodePtr createNode(int data);
void insertAtBeginning(ListNodePtr *head, int data);
void insertAtEnd(ListNodePtr *head, int data);
void printList(ListNodePtr head);
void insertAtPosition(ListNodePtr *head, int data, int position);
void deleteNode(ListNodePtr *head, int data);
void reverseList(ListNodePtr *head);


int main(){
    ListNodePtr head=NULL;
    insertAtEnd(&head,2);
    insertAtEnd(&head,3);
    insertAtEnd(&head,5);
    insertAtEnd(&head,7);
    insertAtEnd(&head,11);
    printf("2,3,5,7,11 are added to the linked list.\n");
    printList(head);
    insertAtEnd(&head,13);
    printf("13 is added to end of the linked list.\n");
    printList(head);
    insertAtPosition(&head,17,3);
    printf("17 is added to 3rd position of the linked list.\n");
    printList(head);
    insertAtBeginning(&head,19);
    printf("19 is added to beginning of the linked list.\n");
    printList(head);
    deleteNode(&head,3);
    printf("3 is deleted from the linked list.\n");
    printList(head);
    printf("The linked list is reversed.\n");
    reverseList(&head);
    printList(head);
    return 0;
}




ListNodePtr createNode(int data){
    ListNodePtr p= malloc(sizeof(ListNode));
    p->data=data;
    p->nextPtr=NULL;
    return p;
}




void insertAtBeginning(ListNodePtr *head, int data){
    ListNodePtr p=createNode(data);
    p->nextPtr=*head;
    *head=p;
    
}




void insertAtEnd(ListNodePtr *head, int data){
    ListNodePtr currPtr = *head;
    ListNodePtr lastPtr=  *head;
    if(currPtr==NULL)
        insertAtBeginning(head,data);
    else{
        while(currPtr!=NULL){
            lastPtr=currPtr;
            currPtr=currPtr->nextPtr;
        }
        lastPtr->nextPtr=createNode(data);
    }
}




void insertAtPosition(ListNodePtr *head, int data, int position){
    ListNodePtr currPtr = *head;
    ListNodePtr lastPtr=  *head;
    int pos=0;

    if(position==0)
        insertAtBeginning(head,data);
    else{
        while(pos!=position){
            lastPtr=currPtr;
            currPtr=currPtr->nextPtr;
            pos++;
        }
        ListNodePtr p=createNode(data);
        lastPtr->nextPtr=p;
        p->nextPtr=currPtr;
    }
}


void deleteNode(ListNodePtr *head, int data){
    ListNodePtr currPtr = *head;
    ListNodePtr lastPtr=  *head;
    if(((*head)->data)==data){
        *head=(*head)->nextPtr;
    }
    else{
        while((currPtr->data)!=data){
            lastPtr=currPtr;
            currPtr=currPtr->nextPtr;
        }
        lastPtr->nextPtr=currPtr->nextPtr;
    }
}


void reverseList(ListNodePtr *head){
    int len=0;
    ListNodePtr currPtr=*head;
    while(currPtr!=NULL){
        currPtr=currPtr->nextPtr;
        len++;
    }


    currPtr=*head;
    int arr[len];
    int i=0;
    while(currPtr!=NULL){
        arr[i]=currPtr->data;
        currPtr=currPtr->nextPtr;
        i++;
    }

    int temp;
    for(int j=0;j<len/2;j++){
        temp=arr[j];
        arr[j]=arr[len-1-j];
        arr[len-1-j]=temp;
    }

    currPtr=*head;
    for(int k=0;k<len;k++){
        currPtr->data=arr[k];
        currPtr=currPtr->nextPtr;
    }
}


void printList(ListNodePtr head){
    ListNodePtr currPtr=head;
    while(currPtr!=NULL){
        printf("%d ",currPtr->data);
        currPtr=currPtr->nextPtr;
    }
    printf("\n");
}



