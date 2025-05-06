#include <iostream>
#include <stdlib.h>

class cll{
    struct node{
        int data;
        struct node* next;
    }*head;
    public:
        cll(){
            head=NULL;
        }
        void insertbeginning(int ele);
        void display();
        int deletebeginning();
        int deleteend();
        void insertend(int ele);
        void insertposn(int ele,int pos);
        int deleteposn(int posn);
        int search(int ele);
};

void cll::insertbeginning(int ele){
    struct node *newnode=(struct node*)malloc(sizeof(node));
    struct node *temp=head;
    if (head!=NULL){
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->data=ele;
        newnode->next=head;
        head=newnode;
    }else{
        head=newnode;
        newnode->data=ele;
        newnode->next=head;
    }
}

void cll::display(){
    struct node *temp=head;
    while(temp->next!=head){
        printf("->%d",temp->data);
        temp=temp->next;
    }printf("->%d",temp->data);
}

int cll::deletebeginning(){
    if (head==NULL){
        return -9999;
    }
    struct node *temp1=head;
    struct node *temp=head;
    int ele=head->data;
    temp1=temp1->next;
    while(temp->next!=head){
        temp=temp->next;
    }
    head=temp1;
    temp->next=head;
    return ele;
}

void cll::insertend(int ele){
    struct node *newnode=(struct node*)malloc(sizeof(node));
    struct node *temp=head;
    newnode->data=ele;
    newnode->next=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newnode;
}

void cll::insertposn(int ele,int pos){
    if (pos==0){
        insertbeginning(ele);
    }else{
        struct node *temp=head;
        struct node *newnode=(struct node*)malloc(sizeof(node));
        for (int i=1;i<pos;i++){
            temp=temp->next;
        }
        newnode->data=ele;
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

int cll::deleteend(){
    if (head==NULL){
        return -9999;
    }
    struct node *temp=head;
    while(temp->next->next!=head){
        temp=temp->next;
    }
    int ele=temp->next->data;
    temp->next=head;
    return ele;
}

int cll::deleteposn(int posn){
    if (head==NULL){
        return -9999;
    }
    if (posn==0){
        int ele=deletebeginning();
        return ele;
    }
    else{
        struct node *temp=head;
        for (int i=1;i<posn;i++){
            temp=temp->next;
        }
        int ele=temp->next->data;
        temp->next=temp->next->next;
        return ele;
    }
}

int cll::search(int ele){
    struct node *temp=head;
    int bool1=0;
    while(temp->next!=head){
        if (temp->data==ele){
            bool1=1;
        }
        temp=temp->next;
    }
    if (temp->data==ele){
        bool1=1;
    }
    if (bool1==1){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int choice;
    int ele;
    int bool1=1;
    class cll l1;
    int a;
    int posn;
    while(bool1){
        printf("\n1)Insert Beginning\n2)Insert End\n3)Insert Position");
        printf("\n4)Delete Beginning\n5)Delete at End\n6)Delete at position");
        printf("\n7)Display\n8)Search\n9)Exit\nEnter Choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                printf("\nEnter no. to be inserted: ");
                scanf("%d",&ele);
                l1.insertbeginning(ele);
                break;
            case 2:
                printf("\nEnter no. to be inserted: ");
                scanf("%d",&ele);
                l1.insertend(ele);
                break;
            case 3:
                printf("\nEnter no. to be inserted: ");
                scanf("%d",&ele);
                printf("\nEnter posn: ");
                scanf("%d",&posn);
                l1.insertposn(ele,posn);
                break;
            case 4:
                a=l1.deletebeginning();
                if (a!=-9999){
                    printf("\nThe deleted element is %d.",a);
                }
                break;
            case 5:
                a=l1.deleteend();
                if (a!=-9999){
                    printf("\nThe deleted element is %d.",a);
                }
                break;
            case 6:
                printf("\nEnter posn: ");
                scanf("%d",&posn);
                a=l1.deleteposn(posn);
                if (a!=-9999){
                    printf("\nThe deleted element is %d.",a);
                }
                break;
            case 7:
                printf("\n");
                l1.display();
                break;
            case 8:
                printf("\nEnter no. to be searched: ");
                scanf("%d",&ele);
                int a;
                a=l1.search(ele);
                if (a==1){
                    printf("\nElement is present");
                }else{
                    printf("\nElement is not present");
                }
            case 9:
                break;
        }
    }
}

