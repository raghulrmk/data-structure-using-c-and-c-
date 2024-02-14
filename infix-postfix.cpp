// Converting Infix to Postfix but without curly braces involved;
#include <iostream>
#include <string.h>
#include <string>
#include <stack>

using namespace std;

void ConvertoPostfix(char*exp, int len) {
    string expression=" ";
    stack<char>S;
    int random=0;
    string temp;
    for(int i=0; i<len; i++) {
        if(i==len-1) {
            expression+=exp[i];
            expression+=S.top();
            S.pop();
            break;
        }
        if(random==2) {
            expression+=S.top();
            S.pop();
            random=0;
        } 
        switch(exp[i]) {
            case 'A'...'Z':
                expression+=exp[i];
                if(random==1) {
                    random++;
                }
                break;
            case '+':
                S.push(exp[i]);
                random++;
                break;
            case '-':
                S.push(exp[i]);
                random++;
                break;
            case '*':
                S.push(exp[i]);
                random++;
                break;
            case '/':
                S.push(exp[i]);
                random++;
                break;
        }
    }
    cout<<expression<<endl;
}
    


int main() {
    char exp[101];
    cout<<"Enter the infix expression to convert it to postfix"<<endl;
    gets(exp);
    ConvertoPostfix(exp,strlen(exp));
}