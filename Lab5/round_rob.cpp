#include <stdio.h>
#include <stdlib.h>
#include "round_rob.h"
using namespace std;

int main(){
    class tasks t1;
    int ele;
    int choice;
    int fix_time;
    cout<<"Enter fixed process execution time: ";
    cin>>fix_time;
    t1.fix_time_fn(fix_time);
    while(1){
        cout<<"1. Insert Process"<<endl;
        cout<<"2. Execute"<<endl;
        cout<<"Enter Choice: "<<endl;
        cin>>choice;
        if (choice==1){
            cout<<"Enter task to be inserted: "<<endl;
            cin>>ele;
            t1.insert_task(ele);
            cout<<"Successfully Inserted"<<endl;
        }
        else if (choice==2){
            t1.execute();
        }
        else{
            cout<<"Enter Valid Option"<<endl;
        }
    }
}