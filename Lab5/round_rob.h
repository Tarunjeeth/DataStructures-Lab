#include <iostream>
#include <stdlib.h>
using namespace std;

class tasks{
    int fix_time;
    struct node{
        int data;
        struct node *next;
    }*head;
    public:
        tasks(){
            head=NULL;
        }
        void fix_time_fn(int ele);
        void insert_task(int ele);
        void display();
        void execute();
};

void tasks::fix_time_fn(int ele){
    fix_time=ele;
    cout<<"Fixed cpu Processing time is "<<fix_time<<endl<<endl;
}

void tasks::insert_task(int ele){
    struct node *newnode=(struct node *)malloc(sizeof(node));
    newnode->data=ele;
    if (head==NULL){
        newnode->next=newnode;
        head=newnode;
    }else{
        struct node *temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        newnode->next=head;
        temp->next=newnode;
    }
}

void tasks::display(){
    if (head==NULL){
        cout<<"No Process in the queue"<<endl<<endl;
    }
    else{  
        struct node *temp=head;
        while(temp->next!=head){
            cout<< temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data<<endl<<endl;
    }
}

void tasks::execute(){
    struct node *temp=head;
    if (temp==NULL){
        cout<<"No Process in the queue"<<endl<<endl;
    }else if (temp->next==temp){
        temp->data=temp->data-fix_time;
        if (temp->data<=0){
            head=NULL;
        }
        display();
    }else{
        temp->data=temp->data-fix_time;
        if (temp->data<=0){
            while (temp->next!=head){
                temp=temp->next;
            }
            temp->next=temp->next->next;
        }
        head=head->next;
        display();
    }
    
}

