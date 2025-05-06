#include <iostream>
#include <stdlib.h>
#define SIZE 5
using namespace std;

class hash1{
    int hashtable[SIZE];
    int cursize;
    public:
        hash1(){
            cursize=0;
            for (int i=0;i<SIZE;i++){
                hashtable[i]=-1;
            }
        }
        int hashfn(int value){
            return value%SIZE;
        }
        int delete1(int);
        void insert(int);
        void display();
        int search(int);
};

void hash1::insert(int data){
    int startindex=hashfn(data);
    int index=startindex;
    int count=0;
    while(hashtable[index]!=-1 && hashtable[index]!=-9999){
        index=(index+(count*count))%SIZE;
        if (cursize/SIZE==1){
            cout<<"The Hashtable is full";
            return;
        }
        count++;
    }
    hashtable[index]=data;
    cursize=cursize+1;
}

void hash1::display(){
    for (int i=0;i<SIZE;i++){
        if (hashtable[i]==-1){
            cout<<"_-_"<<endl;
        }else if(hashtable[i]==-9999){
            cout<<"Tombstone"<<endl;
        }else{
            cout<<"key: "<<i<<"  "<<"value: "<<hashtable[i]<<endl;
        }
    }
}

int hash1::delete1(int data){
    int startindex=hashfn(data);
    int index=startindex;
    if ((cursize/SIZE)==1){
        return -1;
    }
    while(hashtable[index]!=-1 || hashtable[index]==-9999){
        if (hashtable[index]==data){
            hashtable[index]=-9999;
            return 1;
        }
        index=(index+1)%SIZE;
        if (startindex==index){
            break;
        }
    }
    return -1;
}

int hash1::search(int data){
    int startindex=hashfn(data);
    int index=startindex;
    while(hashtable[index]!=-1){
        if (hashtable[index]==data){
            return index;
        }
        index=(index+1)%SIZE;
        if (startindex==index){
            break;
        }
    }
    return -1;
}

int main(){
    class hash1 h1;
    int choice;
    int data;
    while (1)
    {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit" << endl;
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
            int bool1=h1.delete1(data);
            if(bool1==-1){
                cout<<"\nElement is not present in the hashtable.";
            }
            else{
                cout<<"\nElment is deleted";
            }
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
        if (choice==4){
            cout<<"\nHashTable::"<<endl;
            h1.display();
        }
        if(choice==5){
            break;
        }
    }   
}