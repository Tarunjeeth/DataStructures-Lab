#include <iostream>
#include <stdlib.h>
using namespace std;

class queue1{
    int rear=-1;
    int size=0;
    int arr[5];
    public:
        void enqueue(int data);
        int dequeue();
        int peek();
};

void queue1::enqueue(int data){
    if (size==5 && rear==4){
        cout<<"Queue is full";
    }else{
        rear++;
        arr[rear]=data;
        size++;
    }
    
}

int queue1::dequeue(){
    if (size==0 && rear==-1){
        cout<<"Queue is empty";
        return -99;
    }
    else{
        int data=arr[0];
        size--;
        rear--;
        int count=0;
        while(count<size){
            arr[count]=arr[count+1];
            count++;
        }
        count=0;
        return data;
    }
}

int queue1::peek(){
    if (size==0 && rear==-1){
        cout<<"Queue is empty";
        return -99;
    }
    else{
        int data=arr[0];
        return data;
    }
}

int main(){
    class queue1 q1;
    int ele;
    int choice;
    int data;
    while(1){
        cout<<"\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit"<<endl;
        cout<<"\nEnter choice: ";
        cin>>choice;
        if (choice==1){
            cout<<"\nEnter element to be inserted: ";
            cin>>ele;
            q1.enqueue(ele);
        }
        else if (choice==2){
            data=q1.dequeue();
            if (data!=-99){
                cout<<"The deleted element is "<<data;
            }
        }
        else if (choice==3){
            data=q1.peek();
            if (data!=-99){
                cout<<"The first element is "<<data;
            }
        }

    }
}