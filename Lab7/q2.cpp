#include <iostream>
#include <stdlib.h>
using namespace std;

class queues{
    int arr[5];
    int front;
    int rear;
    public:
        queues(){
            rear=-1;
            front=-1;
        }
        void enqueue(int);
        int isfull();
        int dequeue();
        int peek();
};

int queues::isfull(){
    if ((rear+1)%5==front){
        return 1;
    }
    return 0;
}

void queues::enqueue(int ele){
    if(isfull()){
        cout<<"Queue is full"<<endl;
    }
    else{
        if (front==-1 && rear==-1){
            front++;
        }
        rear=(rear+1)%5;
        arr[rear]=ele;
    }
}

int queues::dequeue(){
    int data;
    if (front==-1 && rear==-1){
        cout<<"Queue is full"<<endl;
        return -99;
    }else{
        if (front==rear){
            data=arr[front];
            front=-1;
            rear=-1;
            return data;
        }else{
            data=arr[front];
            front=(front+1)%5;
            return data;
        }

    }

}

int queues::peek(){
    int data;
    if (front==-1 && rear==-1){
        cout<<"Queue is full"<<endl;
        return -99;
    }else{
        data=arr[front];
        return data;
    }
}


int main(){
    int ch;
    int ele;
    class queues s1;
    while (1){
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Peek"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter Choice: ";
        cin>>ch;
        if (ch==1){
            cout<<"Enter element to be pushed: ";
            cin>>ele;
            s1.enqueue(ele);
        }
        else if (ch==2){
            int ele1=s1.dequeue();
            if (ele1!=-99)
                cout<<ele1<<" is the deleted element."<<endl;
        }
        else if (ch==3){
            int ele1=s1.peek();
            if (ele1!=-99)
                cout<<ele1<<" is the peek result."<<endl;
        }
        else if (ch==4){
            break;
        }
    }
}