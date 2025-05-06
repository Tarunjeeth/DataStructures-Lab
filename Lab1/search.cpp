#include <iostream>
#include "sort.h"
using namespace std;

int bin_search(int arr[],int ele,int len){              //binary search
    int low=0;
    int high=len;
    while(low<=high){
        int mid=(low+high)/2;
        if (arr[mid]==ele){
            return 1;
        }
        else if (ele>arr[mid]){
            low=mid+1;
        }
        else if (ele<arr[mid]){
            high=mid-1;
        }

    }
    return 0;
}

int lin_search(int arr[],int ele,int len){              //linear search
    for (int i=0;i<len;i++){
        if (arr[i]==ele){
            return 1;
        }
    }
    return 0;
}

int main(){
    int len;
    int choice;
    int ele;
    cout << "\nEnter length of the array :";            //taking input of array elements
    cin >> len;
    int arr[len];
    for (int i=0;i<len;i++){
        cout<<"\nEnter element no."<<i<<" :";
        cin >> arr[i];
    }
    
    cout << "\n1.Binary Search\n2.Linear Search\nEnter choice: ";       //menu driven
    cin >> choice;

    if (choice==1){
        cout << "\nEnter element to be searched: ";
        cin >> ele;
        int res=bin_search(arr,ele,len);
        if (res==0){
            cout << "\nElement "<< ele <<" is not present in the array";
        }
        if (res){
            cout << "\nElement "<< ele <<" is present in the array";
        }
    }

    else if (choice==2){
        selection(arr,len);
        cout << "\nEnter element to be searched: ";
        cin >> ele;
        int res=bin_search(arr,ele,len);
        if (res==0){
            cout << "\nElement "<< ele <<" is not present in the array";
        }
        if (res){
            cout << "\nElement "<< ele <<" is present in the array";
        }
    }
}