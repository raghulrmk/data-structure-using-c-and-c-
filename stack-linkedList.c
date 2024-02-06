#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node*next;
};

struct Node*stackPointer;

void insert(int x) {
    struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    if(stackPointer==NULL) {
        stackPointer=temp;
        temp->next=NULL;
        return;
    }
    temp->next=stackPointer;
    stackPointer=temp;
}
void pop() {
    struct Node*ptr;
    if(stackPointer==NULL) {
        printf("Since the linked list is empty, so you cant remove a top element\n");
        return;
    }
    ptr=stackPointer;
    stackPointer=stackPointer->next;
    free(ptr);
}
void top() {
    printf("The Top most element is %d\n",stackPointer->data);
}
void check() {
    struct Node*ptr2=stackPointer;
    while(ptr2!=NULL) {
        printf("%d ",ptr2->data);
        ptr2=ptr2->next;
    }
}

int main() {
    insert(2);
    insert(3);
    insert(4);
    
    top();
    check();
}