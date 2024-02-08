#include <iostream>
#include <stack>
#include <string>
#include <string.h>

using namespace std;

void parenthesisCheck(char*ptr, int length) {
    int check=0;
    int random=0;
    
    stack<char>S;
    for(int i=0; i<length; i++) {
        if(ptr[i]=='{' || ptr[i]=='(' || ptr[i]=='[') {
            S.push(ptr[i]);
            check++;
        } 
        else if(ptr[i]=='}' || ptr[i]==')' || ptr[i]==']') {
            check++;
            if(S.empty())  {
                cout<<"Balance parenthesis error"<<endl;
            } else if(ptr[i] =='}') {
                if('{'==S.top()) {
                    S.pop();
                } else {
                    cout<<"Balance parenthesis error"<<endl;
                    return;
                }
            } else if(ptr[i] ==')') {
                if('('==S.top()) {
                    S.pop();
                } else {
                    cout<<"Balance parenthesis error"<<endl;
                    return;
                }
            } else if(ptr[i] ==']') {
                if('['==S.top()) {
                    S.pop();
                } else {
                    cout<<"Balance parenthesis error"<<endl;
                    return;
                }
            }    
        } 
        
        
        
    }
    if(check==0) {
        cout<<"You didnt use parenthessis"<<endl;
    } else if(!S.empty()) {
        cout<<"Balanced parenthesis error"<<endl;
    } else {
        cout<<"Balanced Parenthesis existed"<<endl;
    }
}

int main() {
    char array[101];
    cout<<"Enter a string with parenthesis to check that it contains balanced parenthesis or not"<<endl;
    gets(array);
    parenthesisCheck(array,strlen(array));
}