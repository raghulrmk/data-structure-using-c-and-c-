#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node*previous;
    struct Node*next;
};

struct Node*head;
struct Node*previousptr;
int random=0;

void insert(int x) {
    struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    if(random==0) {
        temp->previous=NULL;
        temp->next=NULL;
        previousptr=temp;
        head=temp;
        
    } else {
        temp->previous=previousptr;
        temp->next=NULL;
        previousptr->next=temp;
        previousptr=temp;
       
    }
    random++;
    
}
void insertatposition(int data, int position) {
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    int check=0;
    struct Node*ptr3=head;
    while(ptr3!=NULL) {
        if(check==position) {
            if(check==0) {
                head=newNode;
                newNode->previous=NULL;
                newNode->next=ptr3;
                ptr3->previous=newNode;
                newNode->data=data;
            } else {
                newNode->previous=ptr3->previous;
                newNode->next=ptr3;
                ptr3->previous->next=newNode;
                ptr3->previous=newNode;
                newNode->data=data;
            }
        }
        check++;
        ptr3=ptr3->next;
    }
}
void print() {                          // printting using iterative method in forward direction;
    struct Node*ptr1=head;
    while(ptr1!=NULL) {
        printf("%d ",ptr1->data);
        ptr1=ptr1->next;
    }
    printf("\n");
}
void reverseprint() {                  // printing using iterative method in backword direction;
    struct Node*nextptr=head;
    struct Node*ptr2;
    while(nextptr!=NULL) {
        if(nextptr->next==NULL) {
            ptr2=nextptr;
            break;
        }
        nextptr=nextptr->next;
    }
    while(ptr2!=NULL) {
        printf("%d ",ptr2->data);
        ptr2=ptr2->previous;
    }
    printf("\n");
}
void deleteatposition(int value,int position) {
        int check=0;
        struct Node*ptr4=head;
        while(ptr4!=NULL) {
            if(ptr4->data==value && check==position) {
                if(check==0) {
                    head=ptr4->next;
                    ptr4->next->previous=NULL;
                    free(ptr4);
                } else {
                    ptr4->previous->next=ptr4->next;
                    ptr4->next->previous=ptr4->previous;
                    free(ptr4);
                }
            }
            check++;
            ptr4=ptr4->next;
        }
}
int main() {
    int n,i,x;
    printf("Enter how many numbers need to inserted: \n");
    scanf("%d",&n);
    for(i=0; i<n; i++) {
        printf("Enter a number \n");
        scanf("%d",&x);
        insert(x);
    }
    print();
    reverseprint();
    insertatposition(2,4);
    print();
    deleteatposition(2,3);
    print();
}