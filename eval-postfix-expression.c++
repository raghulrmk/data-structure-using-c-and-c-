// here we are going to evaluvate the postfix expression using stack;

#include <iostream>
#include <stack>
#include <string>
#include <string.h>

using namespace std;

void evaluvatePostfix(char*exp, int len) {
    int a,b,c;
    stack<int>S;
    string num=" ";
    for(int i=0; i<len; i++) {
        switch(exp[i]) {
            case '0'...'9':
                num+=exp[i];
                break;
            case ' ':
                if(!(num==" ")) {
                    S.push(stoi(num));
                    num=" ";
                    break;
                }
                break;
            case '+':
                a=S.top();
                S.pop();
                b=S.top();
                S.pop();
                c=a+b;
                S.push(c);
                break;
            case '-':
                a=S.top();
                S.pop();
                b=S.top();
                S.pop();
                c=b-a;
                S.push(c);
                break;
            case '*':
                a=S.top();
                S.pop();
                b=S.top();
                S.pop();
                c=a*b;
                S.push(c);
                break;
            case '/':
                a=S.top();
                S.pop();
                b=S.top();
                S.pop();
                c=b/a;
                S.push(c);
                break;
            case '%':
                a=S.top();
                S.pop();
                b=S.top();
                S.pop();
                c=a%b;
                S.push(c);
                break;
        }
    }
    cout<<"The evaluvated value"<<" "<<S.top()<<endl;
}

int main() {
    char expression[101];
    cout<<"Enter the postfix expression to evalvate"<<endl;
    gets(expression);
    evaluvatePostfix(expression,strlen(expression));
    
}