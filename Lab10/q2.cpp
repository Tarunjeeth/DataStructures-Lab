#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int len;
    int noofwords;
    vector <int> scores;
    cin>>len;
    string word;
    for (int i=0;i<len;i++){
        cin>>noofwords;
        vector <string> words;
        int scorea=0;
        int scoreb=0;
        int scorec=0;
        for (int j=0;j<3*noofwords;j++){
            cin>>word;
            words.push_back(word);
        }
        for (int j=0;j<3*noofwords;j++){
            word=words[j];

            if (count(words.begin(),words.end(),word)==1){
                if (j/noofwords==0){
                    scorea+=3;
                }
                else if (j/noofwords==1){
                    scoreb+=3;
                }
                else if (j/noofwords==2){
                    scorec+=3;
                }
            }
            else if(count(words.begin(),words.end(),word)==2){
                if (j/noofwords==0){
                    scorea+=1;
                }
                else if (j/noofwords==1){
                    scoreb+=1;
                }
                else if (j/noofwords==2){
                    scorec+=1;
                }
            }
        }
        scores.push_back(scorea);
        scores.push_back(scoreb);
        scores.push_back(scorec);
    }
    for (int i=0;i<3*len;i++){
        if (i!=0 && i%3==0){
            cout<<"\n";
        }
        cout<<scores[i]<<" ";
    }
}