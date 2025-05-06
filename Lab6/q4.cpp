#include <iostream>
#include <stdlib.h>
#include "stack.h"
using namespace std;

int check(char exp[],stacks &s1,int size){
    for (int i=0;i<size;i++){
        if (exp[i]=='('){
            s1.push(exp[i]);
        }
        else if (exp[i]==')' && s1.isEmpty()){
            return 0;
        }
        else if(exp[i]==')' && s1.peek()=='('){
            s1.pop();
        }
    }
    if (s1.isEmpty()){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int ch;
    char expression[100];
    class stacks s1;
    string postfix;
    while (1){
        cout<<"1. Add Expression"<<endl;
        cout<<"2. Check Balance"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter Choice: ";
        cin>>ch;
        if (ch==1){
            cout<<"Enter Expression: ";
            cin>>expression;
            cout<<'\n';
        }
        else if (ch==2){
            int size=sizeof(expression)/sizeof(char);
            cout<<check(expression,s1,size)<<endl;
            if(check(expression,s1,size)==1){
                cout<<"\nIt is balanced."<<endl;
            }else{
                cout<<"\nIt is not balanced."<<endl;
            }
        }
        else if (ch==3){
            break;
        }
    }
}