#include <iostream>
#include <stdlib.h>
using namespace std;

class stacks{
    char arr[5];
    int current;
    public:
        stacks(){
            current=-1;
        }
        void push(char);
        char pop();
        char peek();
};

void stacks::push(char ele){
    if (current==4){
        cout<<"Stack is Full."<<endl;
    }else{
        current++;
        arr[current]=ele;
        cout<<"Element is pushed into stack"<<endl;
    }
}

char stacks::pop(){
    if (current==-1){
        cout<<"Stack is Empty."<<endl;
        return '0';
    }else{
        char ret=arr[current];
        current--;
        return ret;
    }
}

char stacks::peek(){
    if (current==-1){
        cout<<"Stack is Empty."<<endl;
        return '0';
    }else{
        char ret=arr[current];
        return ret;
    }
}

int main(){
    int ch;
    char ele;
    class stacks s1;
    while (1){
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Peek"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter Choice: ";
        cin>>ch;
        if (ch==1){
            cout<<"Enter element to be pushed: ";
            cin>>ele;
            s1.push(ele);
        }
        else if (ch==2){
            char ele1=s1.pop();
            if (ele1!='0')
                cout<<ele1<<" is the deleted element."<<endl;
        }
        else if (ch==3){
            char ele1=s1.peek();
            if (ele1!='0')
                cout<<ele1<<" is the top element of the stack."<<endl;
        }
        else if (ch==4){
            break;
        }
    }
}