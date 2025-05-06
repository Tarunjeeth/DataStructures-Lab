#include <iostream>
#include <stdlib.h>

class list{
    struct node{
        struct node *prev;
        int data;
        struct node *next;
    }*head,*tail;
    public:
        list(){
            head=NULL;
            tail=NULL;
        }
        void insertbeginning(int);
        void display();
        void display_rev();
        void insertend(int);
        void insertposn(int ele,int posn);
        int deletebeginning();
        int deleteend();
        int deleteposn(int posn);
        int search(int ele);
};

void list::insertbeginning(int ele){
    struct node *newnode=(struct node *)malloc(sizeof(node));
    newnode->data=ele;
    newnode->next=head;
    newnode->prev=NULL;
    if (head!=NULL){
        head->prev=newnode;
    }
    if (tail==NULL){
        tail=newnode;
    }
    head=newnode;
}

void list::insertend(int ele){
    struct node *temp=tail;
    struct node *newnode=(struct node *)malloc(sizeof(node));
    if (head!=NULL){tail->next=newnode;}
    newnode->data=ele;
    newnode->next=NULL;
    newnode->prev=tail;
    if (head==NULL){
        head=newnode;
    }
    tail=newnode;
}

void list::display(){
    struct node *temp=head;
    while(temp!=NULL){
        printf("->%d",temp->data);
        temp=temp->next;
    }
}

void list::display_rev(){
    struct node *temp=tail;
    while(temp!=NULL){
        printf("->%d",temp->data);
        temp=temp->prev;
    }
}

void list::insertposn(int ele,int posn){
    if (posn==0){
        insertbeginning(ele);
    }else{
        struct node *temp=head;
        struct node *newnode=(struct node *)malloc(sizeof(node));
        for (int i=1;i<posn;i++){
            temp=temp->next;
        }
        newnode->data=ele;
        newnode->next=temp->next;
        newnode->prev=temp;
        (temp->next)->prev=newnode;
        temp->next=newnode;
    }
}

int list::deletebeginning(){
    if (head==NULL && tail==NULL){
        printf("\nNo elements in the DataStruct");
        return -9999;
    }else{  
        struct node *temp=head;
        int ele=temp->data;
        head=temp->next;
        head->prev=NULL;
        return ele;
    }
}

int list::deleteend(){
    if (head==NULL && tail==NULL){
        printf("\nNo elements in the DataStruct");
        return -9999;
    }else{
        struct node *temp=tail;
        int ele=tail->data;
        tail->prev->next=NULL;
        tail=temp->prev;
        return ele;
    }
}

int list::deleteposn(int posn){
    if (posn==0){
        int ele=deletebeginning();
        return ele;
    }else{
        struct node *temp=head;
        for (int i=1;i<posn;i++){
            temp=temp->next;
        }
        int ele=temp->next->data;
        if (temp->next->next!=NULL){
            temp->next->next->prev=temp;
            temp->next=temp->next->next;
        }else{
            temp->next=NULL;
        }
        return ele;
    }
}

int list::search(int ele){
    int bool1=0;
    struct node *temp=head;
    while (temp!=NULL){
        if (temp->data==ele){
            bool1=1;
            return 1;
        }
        temp=temp->next;
    }
    
    return 0;
    
}

int main(){
    int choice;
    int ele;
    int a;
    int bool1=1;
    class list l1;
    int posn;
    while(bool1){
        printf("\n1)Insert Beginning\n2)Insert End\n3)Insert Position");
        printf("\n4)Delete Beginning\n5)Delete at End\n6)Delete at position");
        printf("\n7)Display\n8)Display_rev\n9)Search\n10)Exit\nEnter Choice: ");
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
                printf("\n");
                l1.display_rev();
                break;
            case 9:
                printf("\nEnter no. to be searched: ");
                scanf("%d",&ele);
                int a;
                a=l1.search(ele);
                if (a==1){
                    printf("\nElement is present");
                }else{
                    printf("\nElement is not present");
                }
            case 10:
                break;
        }
    }
}