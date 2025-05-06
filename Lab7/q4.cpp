#include <iostream>
#include "stack.h"
using namespace std;

int len(char arr[]){
    int count=0;
    for (int i=0;arr[i]!='\0';i++){
        count++;
    }
    return count;
}

int main(){
    char arr[100];
    char arr1[100];
    int index=0;
    class stacks l1;
    cout<<"Enter Character string: ";
    cin>>arr;
    int len1=len(arr);
    for (int i=0;i<len1;i++){
        if (arr[i]=='+'){
            l1.pop();
        }
        else{
            l1.push(arr[i]);
        }
    }
    cout<<'\n';
    while(!l1.isEmpty()){
        arr1[index++]=l1.pop();
    }
    for (int i=len1-1;i>-1;i--){
        cout<<arr1[i];
    }
}