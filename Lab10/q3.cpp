#include <iostream>
using namespace std;

class heap{
    int arr[100];
    int n;
    public:
        heap(){
            n=0;
        }
        void heapify(int n,int i);
        void insert(int);
        int Delete();
        void display();
        int search(int);
        void sort();
};

void heap::sort(){
    int num=n;
    int arr1[100];
    int count=1;
    for (int i=num;i>=1;i--){
        int temp=Delete();
        arr1[count]=temp;
        count=count+1;

    }
    n=num;
    for (int i=1;i<=num;i++){
        arr[i]=arr1[i];
    }
}

int heap::search(int ele){
    int bool1=0;
    for (int i=1;i<=n;i++){
        if (arr[i]==ele){
            bool1=1;
        }
    }
    return bool1;
}

int heap::Delete(){
    if (n==0){
        cout<<"No elements in the array."<<endl;
        return -9999;
    }
    else{
        int temp=arr[1];
        arr[1]=arr[n];
        n=n-1;
        for (int i=n/2;i>=1;i--){
            heapify(n,i);
        }
        return temp;
    }
}

void heap::display(){
    if(n==0){
        cout<<"No elements in the array."<<endl;
    }
    else{
        cout<<"Elements in the array"<<endl;
        for (int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
        }
    }
}

void heap::insert(int size){
    int ele;
    for (int i=0;i<size;i++){
        cout<<"Enter value "<<i+1<<": ";
        cin>>ele;
        n=n+1;
        arr[n]=ele;
    }
    for (int i=n/2;i>=1;i--){
        heapify(n,i);
    }
}

void heap::heapify(int num,int i){
    int largest=i;
    int l=2*i;
    int r=2*i+1;
    if (l<=num && arr[largest]<arr[l]){
        largest=l;
    }
    if (r<=num && arr[largest]<arr[r]){
        largest=r;
    }
    if (largest!=i){
        int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        heapify(num,largest);
    }
}

int main(){
    class heap h1;
    int choice;
    int ele;
    int data;
    while(1){
        cout<<"\n1. Insert\n2. Delete\n3. Display\n4. Search\n5. Sort\n6. Exit"<<endl;
        cout<<"\nEnter Choice: ";
        cin>>choice;
        if (choice==1){
            cout<<"Enter no.of values to be inserted: ";
            cin>>data;
            h1.insert(data);
        }
        else if(choice==2){
            int temp=h1.Delete();
            if (temp!=-9999){
                cout<<"Deleted Element is"<<temp;
            }
        }
        else if (choice==3){
            h1.display();
        }
        else if (choice==4){
            cout<<"Enter element to be searched: ";
            cin>>ele;
            int bool1=h1.search(ele);
            if (bool1){
                cout<<"Element is present."<<endl;
            }
            else{
                cout<<"Element is not present."<<endl;
            }
        }
        else if(choice==5){
            h1.sort();
        }
        else{
            break;
        }
    }
}