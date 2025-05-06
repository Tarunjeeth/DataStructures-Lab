#include <iostream>
#include <stdlib.h>
using namespace std;

class queue1{
    struct node{
        int data;
        struct node *next;
    }*head; 
    public:
        queue1(){
            head=NULL;
        }
        void enqueue(int);
        int dequeue();
        int peek();
};

void queue1::enqueue(int ele){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=ele;
    if (head==NULL){    
        newnode->next=head;
        head=newnode;
    }else{
        struct node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
    }
}

int queue1::dequeue(){
    int data;
    if(head==NULL){
        cout<<"Queue is empty!";
        return -111;
    }else{
        data=head->data;
        head=head->next;
        return data;
    }
}

int queue1::peek(){
    int data;
    if(head==NULL){
        cout<<"Queue is empty!";
        return -111;
    }else{
        data=head->data;
        return data;
    }
}


int main(){
    class queue1 l1;
    int choice;
    int data;
    while(1){
        cout<<"\n1) Enqueue\n2) Dequeue\n3) Peek\n4) Exit\nEnter Choice: ";
        cin>>choice;
        if (choice==1){
            cout<<"Enter data to be inserted: ";
            cin>>data;
            l1.enqueue(data);
        }
        else if(choice==2){
            data=l1.dequeue();
            if(data!=-111){
                cout<<data<<" is the deleted element";
            }
        }
        else if(choice==3){
            data=l1.peek();
            if(data!=-111){
                cout<<data<<" is the first element";
            }
        }
        else if(choice==4){
            break;
        }
    }
}