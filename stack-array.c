#include <stdlib.h>
#include <stdio.h>

#define ARRAY_SIZE 10

int array[ARRAY_SIZE];
int stackPointer=-1; // stack pointer(top);

void insert(int x) {
    if(stackPointer==ARRAY_SIZE-1) {
        printf("Since the array is full, so you cant insert the value any more \n");
        return;
    }
    stackPointer+=1;
    array[stackPointer]=x;
}
void pop() {   // pop :- removing an element from the top of the stack (first in and last out);
    if(stackPointer==-1) {
        printf("Since the stack is empty, so you cant remove any element from the top of the stack \n");
        return;
    }
    array[stackPointer]=NULL;
    stackPointer-=1;
}
void top() {
    if(stackPointer==-1) {
        printf("Since the stack is empty, so you cant display any element from the top of the stack \n");
        return;
    }
    printf("%d\n",array[stackPointer]);
}
void check() {
    for(int i=0; i<=stackPointer+4; i++) {
        printf("%d ",array[i]);
    }
}
int main() {
    insert(2);
    insert(3);
    insert(4);
    top();
    pop();
    top();
    
}