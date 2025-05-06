#include <iostream>
#include "adt.h"

int main(){
    int choice;
    int subchoice;
    int ele;
    class list l1;
    class list l2;
    class list l3;
    while(1){
        printf("\n1)Insert Element in List1\n2)Insert Element in List2\n3)Merge Into List 3\n4)Display\n5)Exit");
        printf("\nEnter Choice: ");
        scanf("%d",&choice);
        if (choice==1){
            printf("\nEnter Element: ");
            scanf("%d",&ele);
            l1.insertascending(ele);
        }
        else if(choice==2){
            printf("\nEnter Element: ");
            scanf("%d",&ele);
            l2.insertascending(ele);
        }
        else if(choice==3){
            l3.merge(l1);
            l3.merge(l2);
            printf("\nLists merged into list3");
        }
        else if(choice==4){
            printf("\n1)List1\n2)List2\n3)List3");
            printf("\nEnter Sub-Choice: ");
            scanf("%d",&subchoice);
            if (subchoice==1){
                l1.display();
            }else if(subchoice==2){
                l2.display();
            }else if(subchoice==3){
                l3.display();
            }
        }
    }
}