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
        int isEmpty();
};

int stacks::isEmpty(){
    if (head==NULL){
        return 1;
    }else{
        return 0;
    }
}

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