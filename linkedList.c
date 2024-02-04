#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node*next;
};
struct Node*head;
struct Node*ptr;
int random=0;
void insert(int x) {
    struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    if(random!=0) {
        ptr->next=temp;
    }
    if(head==NULL) {
        head=temp;
    } 
    ptr=temp;
    
    random++;

}
void print() {
    struct Node*ptr1=head;
    while(ptr1!=NULL) {
        printf("%d ",ptr1->data);
        ptr1=ptr1->next;
    }
    printf("\n");
}

void insertatposition(int data, int position) {
    struct Node*previous;
    int check=0;
    struct Node*ptr2=head;
    if(position==0) {
        struct Node*headptr=(struct Node*)malloc(sizeof(struct Node));
        headptr->data=data;
        headptr->next=head;
        head=headptr;
    } else {
        while(ptr2!=NULL) {
            if(check==position) {
                struct Node*middle=(struct Node*)malloc(sizeof(struct Node));
                middle->data=data;
                middle->next=ptr2;
                previous->next=middle;
            }
            check++;
            previous=ptr2;
            ptr2=ptr2->next;
        }
    }

}
void deleteposition(int data) {
    int check=0;
    struct Node*ptr3=head;
    struct Node*previous;
    while(ptr3!=NULL) {
        if(ptr3->data==data) {
            if(check==0) {
                head=ptr3->next;
                free(ptr3);
                break;
            }
        }
        if(data==ptr3->data) {
            previous->next=ptr3->next;
            free(ptr3);
            break;
        }
        
        check++;
        previous=ptr3;
        ptr3=ptr3->next;
    }
}
void reverseList() {
    int check=0;
    struct Node*ptr4=head;
    struct Node*nextNode;
    struct Node*iterateptr;
    while(ptr4!=NULL) {
        if(check==0) {
            nextNode=ptr4;
            iterateptr=ptr4->next;
            ptr4->next=NULL;
        } else {
            if(ptr4->next==NULL) {
                head=ptr4;
            }
            iterateptr=ptr4->next;
            ptr4->next=nextNode;
            nextNode=ptr4;
        }
        check++;
        ptr4=iterateptr;

    }
}
void recursivePrint(struct Node*head) {
    if(head!=NULL) {
        printf("%d ",head->data);
        recursivePrint(head->next);
    }
    
}

int main() {
    int i,n,x;
    printf("Enter how many numbers need to be inserted \n");
    scanf("%d",&n);
    for(i=0; i<n; i++) {
        printf("Enter a number \n");
        scanf("%d",&x);
        insert(x);
    }
    print();
    insertatposition(12,0);
    print();
    insertatposition(13,1);
    print();
    insertatposition(14,2);
    print();
    deleteposition(1);
    print(); 
    reverseList();
    print();
    recursivePrint(head);
}   
