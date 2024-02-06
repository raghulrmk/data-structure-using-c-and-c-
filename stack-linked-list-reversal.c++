// Reversing the datas in lined list using stack;

#include <iostream>
#include <stack>
using namespace std;

class Stack {
    public:
    int data;
    Stack*next;
};

Stack*head;
Stack*previous;
void insert(int x) {
    Stack*temp=new Stack();
    temp->data=x;
    if(head==nullptr) {
        head=temp;
        temp->next=NULL;
        previous=temp;
        return;
    }
    previous->next=temp;
    temp->next=nullptr;
    previous=temp;
}
void print() {
    Stack*ptr=head;
    while(ptr!=nullptr) {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

void reverseLinkedList() {
    Stack*ptr=head;
    stack<class Stack*>S;
    while(ptr!=nullptr) {
        S.push(ptr);
        ptr=ptr->next;
    }
    int check=0;
    Stack*presentptr;
    while(!(S.empty())) {
        if(check==0) {
            head=S.top();
            presentptr=S.top();
            presentptr->next=NULL;
            previous=presentptr;
            S.pop();
        } else {
            presentptr=S.top();
            previous->next=presentptr;
            presentptr->next=NULL;
            previous=presentptr;
            S.pop();
        }
        check++;
    }
}

int main() {
    int n,x;
    cout<<"Enter how many numbers need to be inserted inside the linked list:"<<endl;
    cin>>n;
    for(int i=0; i<n; i++) {
        cout<<"Enter a number:"<<endl;
        cin>>x;
        insert(x);
    }
    print();
    reverseLinkedList();
    print();
}