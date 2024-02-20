#include <iostream>
#include <string>
#include <string.h>
#include <stack>

using namespace std;

void ConvertingIntoPostfix(char*exp, int len) {
    string expression="";
    stack<char>S;
    for(int i=0; i<len; i++) {
        switch(exp[i]) {
            case 'A'...'Z':
                expression+=exp[i];
                break;
            case '(':
                S.push(exp[i]);
                break;
            case ')':
                while(!S.empty()) {
                    if(S.top()=='(') {
                        S.pop();
                        break;
                    }
                    expression+=S.top();
                    S.pop();
                }
                break;
            case '+':
                if(S.empty()) {
                    S.push(exp[i]);
                } else {
                    while(!S.empty()) {
                        if(S.top()!='*' && S.top()!='/' && S.top()!='^') {
                            if(S.top()=='+') {
                            expression+=S.top();
                            S.pop();
                            S.push(exp[i]);
                            break;
                            } else {
                                S.push(exp[i]);
                                break;
                            }
                            

                        } else {
                            expression+=S.top();
                            
                        }
                        S.pop();
                        
                    }
                }
                break;
            case '-':
                if(S.empty()) {
                    S.push(exp[i]);
                } else {
                    while(!S.empty()) {
                        if(S.top()!='+' && S.top()!='*' && S.top()!='/' && S.top()!='^') {
                            if(S.top()=='-') {
                            expression+=S.top();
                            S.pop();
                            S.push(exp[i]);
                            break;
                           } else {
                            S.push(exp[i]);
                            break;
                           }
                            
                        } else {
                            expression+=S.top();
                           
                        }
                        S.pop();
                        
                        
                    }
                }
                break;
            case '*':
                if(S.empty()) {
                    S.push(exp[i]);
                } else {
                    while(!S.empty()) {
                        if(S.top()!='/' && S.top()!='^') {
                            if(S.top()=='*') {
                                expression+=S.top();
                                S.pop();
                                S.push(exp[i]);
                                break;
                            } else {
                               S.push(exp[i]);
                               break;
                            }
                        } else {
                            expression+=S.top();
                        }

                        S.pop();
                    }
                }
                break;
            case '/':
                if(S.empty()) {
                    S.push(exp[i]);
                } else {
                    if(S.top()=='^') {
                        expression+=S.top();
                        S.pop();
                        S.push(exp[i]);
                    } else {
                        S.push(exp[i]);
                    }
                }
                break;
            case '^':
                S.push(exp[i]);
                break;
        }
        if(i==len-1) {
            while(!S.empty()) {
                expression+=S.top();
                S.pop();
            }
        }
    }
    cout<<expression<<endl;
}

int main() {
    char exp[101];
    cout<<"Enter the infix expression to convert it into postfix expression"<<endl;
    gets(exp);
    ConvertingIntoPostfix(exp,strlen(exp));
}