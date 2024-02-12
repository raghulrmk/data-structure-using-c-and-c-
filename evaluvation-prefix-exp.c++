#include <iostream>
#include <string>
#include <string.h>
#include <stack>

using namespace std;

void evaluvatPostfix(char*exp, int len) {
    int a,b,c;
    stack<int>S;
    string num=" ";
    
    for(int i=len-1; i>=0; i--) {

        switch(exp[i]) {
            case '0'...'9':
                num+=exp[i];
                break;
            case ' ':
                if(num!=" ") {
                    S.push(stoi(num));
                    num=" ";
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
                c=a-b;
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
                c=a/b;
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
    cout<<"The evaluvated value is"<<" "<<S.top()<<endl;
    
}

int main() {
    char expression[101];
    cout<<"Enter the prefix expression to evaluvate"<<endl;
    gets(expression);
  
    evaluvatPostfix(expression,strlen(expression));

}