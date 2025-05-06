#include <iostream>
#include <stdlib.h>

class sll{                      //class structure
    struct node{
        int data;
        struct node *next;
    }*head;

    public:
        sll(){
            head=NULL;
        }
        void insertbeginning(int ele);
        void display();
        void insertatend(int ele);
        void insertatposition(int ele,int posn);
        int deleteatbegin();
        int deleteatend();
        int deleteatposn(int);
        int search(int);
        void reverselink();
        void displayreverse();
};

void sll::displayreverse(){
    reverselink();
    display();
    reverselink();
}

void sll::reverselink(){
    struct node *prev=NULL,*current=head,*nextnode=head;
    while(nextnode!=NULL){
        nextnode=nextnode->next;
        current->next=prev;
        prev=current;
        current=nextnode;
    }
    head=prev;
}

int sll::deleteatbegin(){      //function to delete at beginning
    if(head==NULL){
        printf("The list is empty.");
        return -9999;
    }
    else{
        struct node *temp=head;
        int ele=temp->data;
        head=temp->next;
        free(temp);
        return ele;
    }
}

int sll::deleteatend(){        //function to delete at the end
    if (head==NULL){
        printf("\nThe list is empty.");
        return -9999;
    }
    else{
        struct node *temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        int ele=temp->next->data;
        temp->next=NULL;
        return ele;
    }
}

int sll::deleteatposn(int posn){       //function to delete data at a given posn
    if (posn==0){
        int fn=deleteatbegin();
        return fn;
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

void sll::insertatend(int ele){         //function to insert element at the end
    if (head==NULL){
        insertbeginning(ele);
    }
    else{
        struct node *temp=head;
        struct node *newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=ele;
        newnode->next=NULL;
        while (temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void sll::insertbeginning(int ele){             //function to insert at beginnning
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=ele;
    newnode->next=head;
    head=newnode;
}

void sll::insertatposition(int ele,int posn){       //function to insert data at a given position
    if (posn==0){
        insertbeginning(ele);
    }
    else{
        struct node *temp=head;
        struct node *newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=ele;
        for (int i=1;i<posn;i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

void sll::display(){                //function to display singly linked list
    struct node *temp=head;
    while(temp!=NULL){
        printf("->%d",temp->data);
        temp=temp->next;
    }
}

int sll::search(int ele){           //function to search for a particular data
    int bool1=0;
    struct node *temp=head;
    while(temp!=NULL){
        if (temp->data==ele){
            bool1=1;
        }
        temp=temp->next;
    }
    if (bool1){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    class sll l1;
    int choice;
    int ele;
    int pos;
    int fn;
    while (1){
        printf("\n1.Insert at Beginning\n2.Insert at end\n3.Insert at Position");
        printf("\n4.Delete at Beginning\n5.Delete at End\n6.Delete at Position\n7.Search");
        printf("\n8.Display\n9.Display Reverse\n10.Reverse Link\n11.Exit");
        printf("\nEnter Choice: ");
        scanf("%d",&choice);
        if (choice==11){
            break;
        }
        switch (choice){
            case 1:
                printf("\nEnter Element to be inserted: ");
                scanf("%d",&ele);
                l1.insertbeginning(ele);
                printf("\nSuccessfully Inserted");
                break;
            case 2:
                printf("\nEnter Element to be inserted: ");
                scanf("%d",&ele);
                l1.insertatend(ele);
                printf("\nSuccessfully Inserted");
                break;
            case 3:
                printf("\nEnter Element to be inserted: ");
                scanf("%d",&ele);
                printf("\nEnter Position: ");
                scanf("%d",&pos);
                l1.insertatposition(ele,pos);
                break;
            case 4:
                fn=l1.deleteatbegin();
                if(fn!=(-9999)){
                    printf("\nThe deleted element is %d.",fn);
                }
                break;
            case 5:
                fn=l1.deleteatend();
                if(fn!=(-9999)){
                    printf("\nThe deleted element is %d.",fn);
                }
                break;
            case 6:
                printf("\nEnter Position to be deleted: ");
                scanf("%d",&pos);
                fn=l1.deleteatposn(pos);
                if(fn!=(-9999)){
                    printf("\nThe deleted element is %d.",fn);
                }
                break;
            case 7:
                printf("\nEnter Element to be searched: ");
                scanf("%d",&ele);
                if(l1.search(ele)){
                    printf("\nElement is Present.");
                }else{
                    printf("\nElement is not found.");
                }
                break;
            case 8:
                l1.display();
                break;
            case 9:
                l1.displayreverse();
                break;
            case 10:
                l1.reverselink();
                printf("\nSuccessfully Reversed.");
                break;
        }
    }

}