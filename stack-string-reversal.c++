//  Going to reverse the string using stack in c++;

#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

void reverseStack(char* name, int length) {
    stack<char>S;
    for(int i=0; i<length; i++) {
        S.push(name[i]);
    }
    for(int i=0; i<length; i++) {
        name[i]=S.top();
        S.pop();
    }
}

int main() {
    char name[101];
    cout<<"Enter the string to be reversed using stack"<<endl;
    gets(name);
    reverseStack(name,strlen(name));
    cout<<"The reversed string: "<<name<<endl;
}