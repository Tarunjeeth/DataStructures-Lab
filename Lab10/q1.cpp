#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int check(vector <int> vec){
    int bool1=1;
    for (int i=0;i<vec.size();i++){
        int num=vec[i];
        if (count(vec.begin(),vec.end(),num)!=1){
            bool1=0;
        }
    }
    return bool1;
}

int main(){
    int testcases;
    int len;
    int num;
    cin>>testcases;
    vector <int> solutions;
    for (int i=0;i<testcases;i++){
        int bool1;
        int min=0;
        cin>>len;
        vector <int> vec;
        for (int j=0;j<len;j++){
            cin>>num;
            vec.push_back(num);
        }
        bool1=check(vec);
        while(!bool1){
            vec.erase(vec.begin());
            bool1=check(vec);
            min=min+1;
        }
        solutions.push_back(min);
    }
    for (int i=0;i<solutions.size();i++){
        cout<<solutions[i]<<endl;
    }
}