#include <iostream>
#include <stdlib.h>
#include "stack.h"
using namespace std;

void evaluate(stacks &s1,string &postfix){
    char ch;
    s1.clear();
    int op1;
    int op2;
    int data;
    for (int i=0;postfix[i]!='\0';i++){
        ch=postfix[i];
        if (isalnum(ch)){
            s1.push(ch);
        }else{
            op1=s1.pop()-'0';
            op2=s1.pop()-'0';
            if (ch=='+'){
                data=op1+op2;
            }
            else if(ch=='-'){
                data=op1-op2;
            }
            else if(ch=='*'){
                data=op1*op2;
            }
            else if(ch=='/'){
                data=op1/op2;
            }
            s1.push(data+'0');
        }
    }
    cout<<s1.pop();
}

void pusher(char exp[], stacks &s1, string &postfix){
    char ch;
    for (int i=0;exp[i]!='\0';i++){
        ch=exp[i];
        if (isalnum(ch)){
            postfix+=ch;
        }else{
            while (!s1.isEmpty()) {
                if ((ch == '+' || ch == '-') && (s1.peek() == '*' || s1.peek() == '/' || s1.peek() == '+' || s1.peek() == '-')) {
                    postfix += s1.pop();
                } else if ((ch == '*' || ch == '/') && (s1.peek() == '*' || s1.peek() == '/')) {
                    postfix += s1.pop();
                } else {
                    break;
                }
            }
            s1.push(ch);
        }
    }
    while(!s1.isEmpty()){
        postfix+=s1.pop();
    }
}



int main(){
    int ch;
    char expression[100];
    class stacks s1;
    string postfix;
    while (1){
        cout<<"1. Get Infix expression"<<endl;
        cout<<"2. Convert Infix"<<endl;
        cout<<"3. Evaluate Postfix"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter Choice: ";
        cin>>ch;
        if (ch==1){
            cout<<"Enter Infix Expression to be pushed: ";
            cin>>expression;
        }
        else if (ch==2){
            int size = strlen(expression);
            pusher(expression,s1,postfix);
            cout<<postfix<<endl;
        }
        else if (ch==3){
            evaluate(s1,postfix);
        }
        else if (ch==4){
            break;
        }
    }
}