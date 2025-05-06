#include <iostream>
#include <stdlib.h>
using namespace std;

class stacks{
    struct node{
        char data;
        struct node *next;
    }*head;
    public:
        stacks(){
            head=NULL;
        }
        void push(char);
        char pop();
        char peek();
};

void stacks::push(char ele){
    struct node *newnode=(struct node *)malloc(sizeof(node));
    newnode->data=ele;
    if (head==NULL){
        newnode->next=head;
        head=newnode;
    }else{
        struct node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        newnode->next=NULL;
        temp->next=newnode;
    }
}

char stacks::pop(){
    if (head==NULL){
        cout<<"Stack is Empty."<<endl;
        return '0';
    }else if(head->next==NULL){
        char ret=head->data;
        head=NULL;
        return ret;
    }
    else{
        struct node *temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        char ret=temp->next->data;
        delete temp->next;
        temp->next=NULL;
        return ret;
    }
}
char stacks::peek(){
    if (head==NULL){
        cout<<"Stack is Empty."<<endl;
        return '0';
    }else if(head->next==NULL){
        char ret=head->data;
        return ret;
    }
    else{
        struct node *temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        char ret=temp->next->data;
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