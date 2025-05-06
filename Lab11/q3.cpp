#include <iostream>
#include <stdlib.h>
#define SIZE 5
using namespace std;

class hash1{
    struct Node{
        int data;
        struct Node* next;
    };
    struct Node* hashtable[SIZE];
    public:
        hash1(){
            for (int i=0;i<SIZE;i++){
                hashtable[i]=NULL;
            }
        }
        int hashfn(int value){
            return value%SIZE;
        }
        void delete1(int);
        void insert(int);
        int search(int);
        int findpos(int);
        void deleteatbegin(int index){
            struct Node *temp=hashtable[index];
            hashtable[index]=temp->next;
        }
        void delete_at_posn(int index,int pos){
            if (pos==0){
                deleteatbegin(index);
            }
            else{
                struct Node *temp=hashtable[index];
                for (int i=1;i<pos;i++){
                    temp=temp->next;
                }
                int ele=temp->next->data;
                temp->next=temp->next->next;
            }
        }
};

int hash1::findpos(int data){
    int startindex=hashfn(data);
    struct Node* temp=hashtable[startindex];
    int pos=0;
    while(temp!=NULL){
        if (temp->data==data){
            break;
        }
        pos=pos+1;
    }
    return pos;
}

void hash1::insert(int data){
    int startindex=hashfn(data);
    struct Node* newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=hashtable[startindex];
    hashtable[startindex]=newnode;
}

int hash1::search(int data){
    int startindex=hashfn(data);
    struct Node* temp=hashtable[startindex];
    int bool1=0;
    while (temp!=NULL && temp->data!=data){
        temp=temp->next;
    }
    if (temp!=NULL && temp->data==data){
        return startindex;
    }else{
        return -1;
    }
}

void hash1::delete1(int data){
    int startindex=hashfn(data);
    struct Node* temp=hashtable[startindex];
    int bool1=search(data);
    if(bool1!=-1){
        int pos=findpos(data);
        delete_at_posn(startindex,pos);
    }
    else{
        cout<<"Element is not present";
    }
}

int main(){
    class hash1 h1;
    int choice;
    int data;
    while (1)
    {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        if (choice==1){
            cout<<"\nEnter Data to be inserted: ";
            cin>>data;
            h1.insert(data);
        }
        if (choice==2){
            cout<<"\nEnter Data to be deleted: ";
            cin>>data;
            h1.delete1(data);
        }
        if (choice==3){
            cout<<"\nEnter Data to be searched: ";
            cin>>data;
            int bool1=h1.search(data);
            if(bool1==-1){
                cout<<"\nElement is not present in the hashtable.";
            }
            else{
                cout<<"\nElment is present with key "<<bool1;
            }
        }
        if(choice==4){
            break;
        }
    }
}